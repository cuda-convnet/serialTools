#pragma once


using namespace System;
using namespace System::Threading;
using namespace System::Diagnostics;

//
//  TODO   make calibration values persistent
//

#define amtTwaRecs 10
#define totalTwaWeights  (amtTwaRecs * (amtTwaRecs + 1))/2

public  class AdcTwaRec 
{
	private:
		float origAdcVal;
		float twaAdcVal;
		float twaStepDiff;
	
	public:
		AdcTwaRec();
		AdcTwaRec(int);
		virtual ~AdcTwaRec();
		void calcStep();
		int currentAdcVal();

	friend class TwaCalculator; 
};


public  class TwaCalculator
{
	public: 
		TwaCalculator();
		virtual ~TwaCalculator();
		void insertTop(int);
		int currentAdcTwaVal();
		static void initClass();
		static void destructClass();
		static TwaCalculator* twaCalcSingleton;
	private:
		AdcTwaRec*  twaArray[amtTwaRecs];
		float curAdcTwaVal;
		int amtValuesAdded;
};

public ref class TorqueCalc {
public:

	TorqueCalc();
	virtual ~TorqueCalc();
	static void updateADCVal(int);

	static void setLowRefNcm(int ncm);
	static void setHighRefNcm(int ncm);

	static void setLowMinusRefNcm(int ncm);
	static void setHighMinusRefNcm(int ncm);
	static void setMidPointADC();

	static void clearRefs();
	static bool isCalibValid(String^*);
	static void resultTorqueNcm(int&, int&, int&);

	static void initClass();
	static void destructClass();

private:
	static Semaphore^  calcMutex;
	static int adcVal;

	static int lowRefADC;
	static int highRefADC;
	static int  highRefNcm;
	static int  lowRefNcm;

	static int lowMinusRefADC;
	static int highMinusRefADC;
	static int  highMinusRefNcm;
	static int  lowMinusRefNcm;

	static int midPointADC;

	static void resultTorqueNcmInner(int&, int&);
	static void calcLinear(int adcV,int lowNcm, int highNcm, int lowADC, int highADC, int& resNcm);
	static bool refsValid(int highNcm,int lowNcm,int highADC,int lowADC,String^ minusS,String^* resS);
	
	static void setLowRefADC(int adc);
	static void setHighRefADC(int adc);
	static void setLowMinusRefADC(int adc);
	static void setHighMinusRefADC(int adc);
};