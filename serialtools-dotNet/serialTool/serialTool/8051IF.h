#include "stdafx.h"
//#include <commctrl.h>
#include "CSerial.h"

using namespace System;
using namespace System::Threading;
using namespace System::Diagnostics;


//typedef bool BOOL;
typedef int HANDLE;
//typedef int DWORD;

#define WINAPI

public ref class C8051IF {
public:

	BOOL isDeviceRunning();

	C8051IF();
	virtual ~C8051IF();
	int start();
	void stop();
	void getMeasure(double& hum, double& temp, DWORD& cnt);
	static int initClass();
	static CSerial^ commPort;
	

private:
	BOOL deviceRunning;
	void setDeviceRunning(BOOL runOK);

	ref class Mutex{
		Mutex(HANDLE* lpMutex);
		~Mutex();
		HANDLE mutex;
	};
	

	Thread^ hygroThread;  // Thread reading values from Sensor
	void incMeasure(double hum, double temp);
	BOOL getSensorValues();
	static HANDLE hygroStopEvent;  // event to communicate to the hygrothread
									// that it shall stop
	static HANDLE hygroMutex;		// thread concurrency synchronisation
	static double temperature;
	static double humidity;
	static DWORD measureCount;
	void logException(Exception^ ex1);
	
	static void hygroThreadMethod(); 
};
