#include "stdafx.h"
#include "TorqueCalc.h"
#include "8051IF.h"


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
		calcMutex->Release();
	}

	void TorqueCalc::setLowRefADC(int adc)
	{
		calcMutex->WaitOne();
		lowRefADC = adc;
		calcMutex->Release();
	}

	void TorqueCalc::setHighRefADC(int adc)
	{
		calcMutex->WaitOne();
		highRefADC = adc;
		calcMutex->Release();
	}

	void TorqueCalc::setLowRefNcm(int ncm)
	{
		calcMutex->WaitOne();
		lowRefNcm = ncm;
		calcMutex->Release();
	}

	void TorqueCalc::setHighRefNcm(int ncm)
	{
		calcMutex->WaitOne();
		highRefNcm = ncm;
		calcMutex->Release();
	}


	void TorqueCalc::initClass()
	{
		lowRefADC = 0;
		highRefADC = 0;
		lowRefNcm = 0;
		highRefNcm = 0;
		calcMutex =   gcnew Semaphore( 1,1 );
	}

	void TorqueCalc::resultTorqueNcmInner(int& adc,int& Ncm)
	{
		calcMutex->WaitOne();
		if (isCalibValid(String::Format(""))) {
			
			float dADC = (float) (highRefADC - lowRefADC);
			float dNcm = (float) (highRefNcm - lowRefNcm);
			float lNcm = (float) lowRefNcm;
			float lAdc = (float) lowRefADC;
			float xAdc = (float) adcVal;

			float resF = lNcm + (dNcm/dADC) * (xAdc - lAdc);
			Ncm = (int) resF;
			adc = adcVal;
			
		} else {
			adc= 0;
			Ncm = 0;
		}
	}


	void TorqueCalc::resultTorqueNcm(int& adc,int& Ncm)  
	{
		calcMutex->WaitOne();
		resultTorqueNcmInner( adc, Ncm);  // inner method to make sure, mutex gets released in case of
										// exception and in case of  a return in mid of code or....
		calcMutex->Release();
	}

	bool TorqueCalc::isCalibValid(String^ resS)
	{	
		bool res = false;
		if ((lowRefADC > 0) && (highRefADC > 0) && (lowRefNcm > 0) && (highRefNcm > 0)) {
			if  (lowRefNcm < highRefNcm) {
				if (lowRefADC < highRefADC) {
					res = true;
				} else {
					resS->Insert(resS->Length,String::Format("lowRefADC >= highRefADC"));
				}
			} else {
				resS->Insert(resS->Length,String::Format("lowRefNcm >= highRefNcm"));
			}
		} else {
			resS->Insert(resS->Length,String::Format("some refs are 0"));
		}
		return res;
	}

	void TorqueCalc::clearRefs()
	{
		lowRefADC = 0;
		highRefADC = 0;
		lowRefNcm = 0;
		highRefNcm = 0;
	}