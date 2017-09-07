#include "stdafx.h"
#include "8051IF.h"



HANDLE C8051IF::hygroStopEvent;
HANDLE C8051IF::hygroMutex;

double C8051IF::temperature;
double C8051IF::humidity;
DWORD C8051IF::measureCount;



//  PN 8. Nov 2005
//
//  standard way of method access synchronisation
//
//  let the constructor/destructor access the semaphore in the
//   frame of a method
//
//  do not remove the method local Mutex m variables, even they seem 
//  not explicitely be used.
//

C8051IF::Mutex::Mutex(HANDLE* lpMutex)
{
	mutex = * lpMutex;
//	WaitForSingleObject(mutex,INFINITE);
}

C8051IF::Mutex::~Mutex()
{
//	SetEvent(mutex);
}
	



C8051IF::C8051IF() 
{
	//hygroStopEvent = CreateEvent(NULL,TRUE,FALSE,NULL);
	//hygroMutex = CreateEvent(NULL,FALSE,TRUE,NULL);
	
//	TRACE0("\nconstuctor C8051IF  %i\n");
	
/*	if (! start())  {
		MessageBox(NULL,"error on HygroIF start","error", MB_OK);
	}
	*/
}


C8051IF::~C8051IF()
{
//	TRACE0("\ndestructor C8051IF\n");
}


int C8051IF::start()
{
//	TRACE0("\nstart C8051IF\n");
//	commPort.Open_port();

//	hygroThread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)hygroThreadMethod,this,0,NULL);

	return 1;
}

void C8051IF::stop()
{
	DWORD tmOut;
//	TRACE0("\nstop C8051IF\n");
////	commPort.Close_port();
//	SetEvent(hygroStopEvent);
//	tmOut = GBSerialReadTotalTimeoutConstant  \
//			+ GBReadIntervalTimeout  \
//			+ 2000;  //  max calculation time
//
//	WaitForSingleObject(hygroThread,tmOut);
}


/*
long WINAPI C8051IF::hygroThreadMethod(void* pParam)
{
	int step = 0;

	
	C8051IF* HSIF = (C8051IF*) pParam;
	TRACE0("\nHYGROTHREAD::hygro Thread Started\n");

	while (WaitForSingleObject(hygroStopEvent,100) != WAIT_OBJECT_0) {
		++ step;
//		TRACE1("HYGROTHREAD::hygro Thrad step %i\n",step);

		if (! HSIF->getSensorValues()) {
			TRACE0("\nHYGROTHREAD::hygro Thread error getting values");
		}
	}
	TRACE0("\nHYGROTHREAD::hygro Thrad Returning\n");
	return 0;
}
*/

void C8051IF::incMeasure(double hum, double temp)
{
//	Mutex m (&hygroMutex);

	measureCount ++;
	temperature = temp;
	humidity = hum;
	deviceRunning = true;
}

void C8051IF::getMeasure(double& hum, double& temp, DWORD& cnt)
{
//	Mutex m (&hygroMutex);

	cnt = measureCount;
	temp = temperature;
	hum = humidity;
}


BOOL C8051IF::getSensorValues()
{
	char buffer [300];
	DWORD amtRcv;

//	memset(&buffer, 0, sizeof(buffer));

//	commPort.Read_port(&buffer, sizeof(buffer), &amtRcv);

	if (amtRcv > 0) {

/*		char* tempS;
		char* endS;
		double rots = 0.0;
		double rpm;

		tempS = strstr(buffer,"*")+1;
		endS = strstr(tempS,"*");


		if ((tempS != NULL) && (endS != NULL)) {
			TRACE1("temps found %s\n",tempS);
			rots = strtoul(tempS ,NULL,10) ;
		}
		*/
//		temp = temp / 100;
//		double hyd = strtoul (hydS, &hydS + 4, 0x10);
//		hyd = hyd / 200;

//		TRACE3("\n%i received: %i  %s\n",measureCount,amtRcv, buffer);
		incMeasure(0.0,0.0);

//		TRACE2("\nV01: %s %f\n",tempS, temp);
//		TRACE2("\nV02: %s %f\n",hydS, hyd);
	
	//	incMeasure(hyd,temp);


		// timer on 8053 takes 1984 ms

/*		incMeasure(0.0,0.0);


		rpm = (rots * 30.0) / 1.991;


	    TRACE3("at %i [ms] C8051IF received i bytes: s rots: %f rpm: %f\n",GetTickCount(), rots, rpm);

		AfxGetMainWnd()->PostMessage(WM_CLOSE, 0, 0);




 */

	}  else
	{
//		setDeviceRunning(FALSE);
//		TRACE2("%i nothing received: %i\n",measureCount, amtRcv);
		incMeasure(0.0,0.0);
	}
	
	return  true;
}

BOOL C8051IF::isDeviceRunning()
{
//	Mutex m (&hygroMutex);
	return deviceRunning;
}

void C8051IF::setDeviceRunning(BOOL runOK)
{
//	Mutex m (&hygroMutex);
	deviceRunning = runOK;
}
