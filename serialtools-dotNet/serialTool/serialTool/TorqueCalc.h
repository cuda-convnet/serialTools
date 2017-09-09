#pragma once


using namespace System;
using namespace System::Threading;
using namespace System::Diagnostics;

public ref class TorqueCalc {
public:

	TorqueCalc();
	virtual ~TorqueCalc();
	static void updateADCVal(int);

	static void setLowRefADC(int adc);
	static void setHighRefADC(int adc);
	static void setLowRefNcm(int ncm);
	static void setHighRefNcm(int ncm);
	static void clearRefs();
	static bool isCalibValid(String^);
	static void resultTorqueNcm(int&, int&);

	static void initClass();

private:
	static Semaphore^  calcMutex;
	static int adcVal;
	static int lowRefADC;
	static int highRefADC;
	static int  highRefNcm;
	static int  lowRefNcm;
	static void resultTorqueNcmInner(int&, int&);


};