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
#define applicationMsgSize   17

public ref class C8051IF {
public:

	BOOL isDeviceRunning();

	C8051IF();
	virtual ~C8051IF();
	int start();
	void stop();
	void getMeasure(double& hum, double& temp, DWORD& cnt);
	BOOL getSensorValues();
	static int initClass();

	
private:
	static CSerial^ commPort;
	BOOL deviceRunning;
	void setDeviceRunning(BOOL runOK);	

	static Thread^ hygroThread;  // Thread reading values from Sensor
	void incMeasure(double hum, double temp);
	static Semaphore^ hygroStopEvent;  // event to communicate to the hygrothread
									// that it shall stop
	Semaphore^  hygroMutex;		// thread concurrency synchronisation
	double temperature;
	double humidity;
	DWORD measureCount;
	static void logException(Exception^ ex1);
	
	static void hygroThreadMethod(); 
	static C8051IF^ singleton8051IF;
	static String^ commPortName;
};
