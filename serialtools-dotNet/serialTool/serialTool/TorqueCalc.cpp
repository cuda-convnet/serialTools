#include "stdafx.h"
#include "TorqueCalc.h"


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

	void TorqueCalc::resultTorqueNcm(int& adc,int& Ncm)  
	{
		calcMutex->WaitOne();
		if (isCalibValid()) {
			
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

		calcMutex->Release();
	}

	bool TorqueCalc::isCalibValid()
	{	
		bool res = false;
		if ((lowRefADC > 0) && (highRefADC > 0) && (lowRefNcm > 0) && (highRefNcm > 0)
			&& (lowRefADC < highRefADC) && (lowRefNcm < highRefNcm)) {

			res = true;
		}
		return res;
	}
