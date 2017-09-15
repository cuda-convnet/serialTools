#include "stdafx.h"
#include "TorqueCalc.h"
#include "8051IF.h"


	AdcTwaRec::AdcTwaRec()
	{
		origAdcVal = 0;
		twaAdcVal = 0;
		twaStepDiff = 0;
	}

	AdcTwaRec::AdcTwaRec(int adcV)
	{
		origAdcVal = (float) adcV;
		twaAdcVal = (float) adcV;
		twaStepDiff = ((float)adcV)/((float) amtTwaRecs);
	}

	AdcTwaRec::~AdcTwaRec()
	{
	}

	void AdcTwaRec::calcStep()
	{
		twaAdcVal -= twaStepDiff; 
	}

	int AdcTwaRec::currentAdcVal()
	{
		int res = 0;
		res = (int) twaAdcVal;
		return res;
	}

	TwaCalculator* TwaCalculator::twaCalcSingleton =  nullptr;
	
	TwaCalculator::TwaCalculator()
	{
		for (int i1 = 0; i1 < amtTwaRecs; ++i1) {
			twaArray[i1] = new AdcTwaRec();
		}
		amtValuesAdded = 0;
	}

	TwaCalculator::~TwaCalculator()
	{
		for (int i1 = 0; i1 < amtTwaRecs; ++ i1) {
			delete twaArray[i1];
		}
	}

	void TwaCalculator::insertTop(int topVal)
	{
		for (int i1 = amtTwaRecs - 1; i1 > 0; -- i1) {
			twaArray[i1] = twaArray[i1-1];
			twaArray[i1]->calcStep();
		}
		delete twaArray[0];
		twaArray [0] = new AdcTwaRec(topVal);
		float sumAdc = 0.0;
		for (int i1 = 0; i1 < amtTwaRecs; ++ i1) {
			sumAdc += twaArray[i1]->twaAdcVal;
		}
		curAdcTwaVal = sumAdc / ((float) totalTwaWeights);
		++amtValuesAdded;
	}

	void TwaCalculator::initClass()
	{
		twaCalcSingleton = new TwaCalculator();
	}

	void TwaCalculator::destructClass()
	{
		delete twaCalcSingleton;
	}
	                            
	int TwaCalculator::currentAdcTwaVal()
	{
		int res = 0;
		if (amtValuesAdded >= amtTwaRecs ) {
			res = (int) curAdcTwaVal;
		}
		return res;
	}


	TorqueCalc::TorqueCalc()
	{
	}

	TorqueCalc::~TorqueCalc()
	{
	}

	void TorqueCalc::updateADCVal(int aVal)
	{
		calcMutex->WaitOne();
		adcVal = aVal;
		TwaCalculator::twaCalcSingleton->insertTop(adcVal);
		calcMutex->Release();
	}

	void TorqueCalc::setLowRefADC(int adc)
	{
		lowRefADC = adc;
	}

	void TorqueCalc::setHighRefADC(int adc)
	{
		highRefADC = adc;
	}

	void TorqueCalc::setLowRefNcm(int ncm)
	{
		calcMutex->WaitOne();
		setLowRefADC(adcVal);
		lowRefNcm = ncm;
		calcMutex->Release();
	}

	void TorqueCalc::setHighRefNcm(int ncm)
	{
		calcMutex->WaitOne();
		setHighRefADC(adcVal);
		highRefNcm = ncm;
		calcMutex->Release();
	}

	void TorqueCalc::setLowMinusRefADC(int adc)
	{
		lowMinusRefADC = adc;
	}

	void TorqueCalc::setHighMinusRefADC(int adc)
	{
		highMinusRefADC = adc;
	}

	void TorqueCalc::setLowMinusRefNcm(int ncm)
	{
		calcMutex->WaitOne();
		setLowMinusRefADC(adcVal);
		lowMinusRefNcm = ncm;
		calcMutex->Release();
	}

	void TorqueCalc::setHighMinusRefNcm(int ncm)
	{
		calcMutex->WaitOne();
		setHighMinusRefADC(adcVal);
		highMinusRefNcm = ncm;
		calcMutex->Release();
	}

	void TorqueCalc::initClass()
	{
		clearRefs();
		adcVal = 0;
		midPointADC=0;
		calcMutex =   gcnew Semaphore( 1,1 );
		TwaCalculator::initClass();
	}

	void TorqueCalc::destructClass()
	{
		TwaCalculator::destructClass();
	}

	void TorqueCalc::calcLinear(int adcV,int lowNcm, int highNcm, int lowADC, int highADC, int& resNcm)
	{
		float dADC = (float) (highADC - lowADC);
		float dNcm = (float) (highNcm - lowNcm);
		float lNcm = (float) lowNcm;
		float lAdc = (float) lowADC;
		float xAdc = (float) adcV;

		float resF = lNcm + (dNcm/dADC) * (xAdc - lAdc);
		resNcm = (int) resF;
	}

	void TorqueCalc::resultTorqueNcmInner(int& adc,int& Ncm)
	{
		String^ st1 = String::Format(""); 
		adc = adcVal;
		if (isCalibValid(&st1) && C8051IF::isInterfaceRunning(&st1)) {
			if (adcVal >= midPointADC) {
				calcLinear(adcVal,lowRefNcm,highRefNcm,lowRefADC,highRefADC,Ncm);
			adc = adcVal;
			} else {
				calcLinear(adcVal,lowMinusRefNcm,highMinusRefNcm,lowMinusRefADC,highMinusRefADC,Ncm);
			}
			
		} else {
			Ncm = 0;
		}
	}


	void TorqueCalc::resultTorqueNcm(int& adc,int& Ncm, int& twaVal)  
	{
		calcMutex->WaitOne();
		resultTorqueNcmInner( adc, Ncm);  // inner method to make sure, mutex gets released in case of
										// exception and in case of  a return in mid of code or....
		twaVal = TwaCalculator::twaCalcSingleton->currentAdcTwaVal();
		calcMutex->Release();
	}

	bool TorqueCalc::refsValid(int highNcm,int lowNcm,int highADC,int lowADC,String^ minusS,String^* resS)
	{
		bool res = false;
		if ((lowADC > 0) && (highADC > 0) && (lowNcm > 0) && (highNcm > 0)) {
			if  (lowNcm < highNcm) {
				if (lowADC < highADC) {
					res = true;
				} else {
					*resS += String::Format(minusS + "lowRefADC >= highRefADC");
				}
			} else {
				*resS += String::Format(minusS +"lowRefNcm >= highRefNcm");
			}
		} else {
			*resS += String::Format(minusS +"some refs are 0");
		}
		return res;
	}

	bool TorqueCalc::isCalibValid(String^* resS)
	{	
		bool res = false;
		res = (refsValid(highRefNcm,lowRefNcm,highRefADC,lowRefADC,"",resS))
			&& (refsValid(highMinusRefNcm,lowMinusRefNcm,lowMinusRefADC,highMinusRefADC,"minus: ",resS ));
				// lowMinusADC must be higher than highMinusRefADC
		if (res)  {
			if (lowMinusRefNcm < lowRefNcm) {
				if (lowMinusRefADC < lowRefADC) {
					if ((midPointADC < lowRefADC) && (lowMinusRefADC < midPointADC)) {
					} else {  
						res= false;
						*resS= String::Format("midPointADC must be between lowMinusRefADC and lowRefADC");
					}
				} else {
					res= false;
					*resS = String::Format("lowMinusRefADC must be smaller than lowRefADC");
				}
			} else 
			{
				res = false;
				*resS= String::Format("lowMinusRefNcm must be lower than lowRefNcm");
			}
		}
		return res;
	}



	void TorqueCalc::clearRefs()
	{
		lowRefADC = 0;
		highRefADC = 0;
		lowRefNcm = 0;
		highRefNcm = 0;

		midPointADC=0;

		lowMinusRefADC = 0;
		highMinusRefADC = 0;
		lowMinusRefNcm = 0;
		highMinusRefNcm = 0;
	}

	void TorqueCalc::setMidPointADC()
	{
		calcMutex->WaitOne();
		midPointADC = adcVal;
		calcMutex->Release();
	}