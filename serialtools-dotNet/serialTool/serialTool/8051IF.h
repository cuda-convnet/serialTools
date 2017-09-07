#include "stdafx.h"
//#include <commctrl.h>
//#include "CSerial.h"



typedef bool BOOL;
typedef int HANDLE;
typedef int DWORD;

#define WINAPI

class C8051IF {
public:

	BOOL isDeviceRunning();

	C8051IF();
	virtual ~C8051IF();
	int start();
	void stop();
	void getMeasure(double& hum, double& temp, DWORD& cnt);

private:
	BOOL deviceRunning;
	void setDeviceRunning(BOOL runOK);

	class Mutex{
	public:
		Mutex(HANDLE* lpMutex);
		~Mutex();
		HANDLE mutex;
	};
	

	HANDLE hygroThread;  // Thread reading values from Sensor
	void incMeasure(double hum, double temp);
	BOOL getSensorValues();
	static HANDLE hygroStopEvent;  // event to communicate to the hygrothread
									// that it shall stop
	static HANDLE hygroMutex;		// thread concurrency synchronisation
	static double temperature;
	static double humidity;
	static DWORD measureCount;
//	CSerial commPort;
	
//	static long WINAPI C8051IF::hygroThreadMethod(void* pParam); 
};
