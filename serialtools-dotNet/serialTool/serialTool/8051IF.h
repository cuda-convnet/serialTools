#pragma once

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
#define applicationMsgSize   0x0d

public ref class C8051IF {
public:

	BOOL isDeviceRunning();

	C8051IF();
	virtual ~C8051IF();
	int start(String^);
	void stop();
	void getMeasure(int& );
	BOOL getSensorValues();
	static int initClass();
	static bool isInterfaceRunning(String^*);
	static C8051IF^ singleton8051IF;
	
private:
	static CSerial^ commPort;
	BOOL deviceRunning;
	BOOL threadRunning;
	void setDeviceRunning(BOOL runOK);	

	static Thread^ hygroThread;  // Thread reading values from Sensor
	void incMeasure(int);
	static Semaphore^ hygroStopEvent;  // event to communicate to the hygrothread
									// that it shall stop
	Semaphore^  hygroMutex;		// thread concurrency synchronisation
	int torqueADCval;
	DWORD measureCount;
	static void logException(Exception^ ex1);
	
	static void hygroThreadMethod(); 
	
	static String^ comPortName;
};
