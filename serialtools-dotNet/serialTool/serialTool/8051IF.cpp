#include "stdafx.h"
#include "8051IF.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TorqueCalc.h"

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


	
C8051IF::C8051IF() 
{
	try {
		hygroStopEvent =   gcnew Semaphore( 0,1 );
		hygroMutex =   gcnew Semaphore( 1,1 );
		deviceRunning = false;
		threadRunning = false;
	}
	catch (Exception^ ex)  {
			logException(ex);
	}
}

C8051IF::~C8051IF()
{
//	TRACE0("\ndestructor C8051IF\n");
}


int C8051IF::start(String^ comName)
{
	if (threadRunning == true) {
		Debug::WriteLine("C8051IF::start needs to stop previous thread");
		stop();
	}
	try {
		Debug::WriteLine(String::Format("\nstart C8051IF port: %s",comName));
		comPortName = comName;
		commPort->Open_port(comPortName); 

		hygroThread = gcnew Thread(gcnew ThreadStart(C8051IF::hygroThreadMethod));
		hygroThread->Start();
	}
	catch (Exception^ ex)  {
			logException(ex);
	}
	threadRunning = true;
	return 1;
}

void C8051IF::stop()
{
	DWORD tmOut;

	commPort->Close_port();

	hygroStopEvent->Release();

	tmOut = GBSerialReadTotalTimeoutConstant  \
			+ GBReadIntervalTimeout  \
			+ 2000;  //  max calculation time

	hygroThread->Join(tmOut);
	threadRunning = false;
}


//static void C8051IF::hygroThreadMethod()
void C8051IF::hygroThreadMethod()
{
	int step = 0;
	
	Debug::WriteLine("HYGROTHREAD::hygro Thread Started");

	while (! hygroStopEvent->WaitOne(100) )  {
		++ step;
		Debug::WriteLine(String::Format("HYGROTHREAD::hygro Thrad step %i",step));

		if (! C8051IF::singleton8051IF->getSensorValues()) {
			Debug::WriteLine("HYGROTHREAD::hygro Thread error getting values");
		}
	}
	Debug::WriteLine("HYGROTHREAD::hygro Thrad Returning");
}


void C8051IF::incMeasure(int adcVal)
{
	hygroMutex->WaitOne();

	torqueADCval = adcVal;
	measureCount ++;

	hygroMutex->Release();
	TorqueCalc::updateADCVal(adcVal);
}

void C8051IF::getMeasure(int& adcVal)
{
	hygroMutex->WaitOne();

	adcVal = torqueADCval;

	hygroMutex->Release();
}


#define bufferSz 300

BOOL C8051IF::getSensorValues()
{
	char buffer [bufferSz];
	int amtRcv = 0;
	BOOL res = false;

	memset(&buffer, 0, sizeof(buffer));

	array<Byte>^ bufferx;
	bufferx = gcnew array<Byte>(bufferSz);

	commPort->Read_port(bufferx,bufferSz,&amtRcv);

	if (amtRcv == applicationMsgSize ) {

		for (int i1 = 0; i1 < amtRcv; ++ i1) {
			buffer[i1] = bufferx[i1];
		}

		char* torqueS;


		torqueS = strstr(buffer,"01V")+4;
	
		*(torqueS+5) = 0;

		long torqueI = strtoul(torqueS ,NULL,0x0A);

		incMeasure(torqueI);

		setDeviceRunning(true);
		res = true;

	} else {
		Debug::WriteLine(String::Format("getSensorValues invalid amt chars: %i",amtRcv));
		setDeviceRunning(false);
	}

	return  res;
}

BOOL C8051IF::isDeviceRunning()
{
	BOOL res;
	hygroMutex->WaitOne();

	res= deviceRunning;

	hygroMutex->Release();
	return res;
}

void C8051IF::setDeviceRunning(BOOL runOK)
{
	hygroMutex->WaitOne();

	deviceRunning = runOK;

	hygroMutex->Release();
}

void C8051IF::logException(Exception^ ex1)
{
	Debug::WriteLine(String::Format("C8051IF exception %s source: %s\nmessage : %s\nstack: %s",ex1->ToString(),ex1->Source,ex1->Message,ex1->StackTrace));
}

 int C8051IF::initClass()
{
	C8051IF::commPort = gcnew CSerial();
	C8051IF::singleton8051IF = gcnew C8051IF();
	return 0;
}