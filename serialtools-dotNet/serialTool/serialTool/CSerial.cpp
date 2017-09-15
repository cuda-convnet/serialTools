#include "stdafx.h"
#include "CSerial.h"
#include "Form1.h"


CSerial::CSerial(){
	_serialPort = gcnew SerialPort();
};


CSerial::~CSerial(){
};

void CSerial::logException(Exception^ ex1)
{
serialTool::Form1::logException(ex1);
//	Debug::WriteLine(String::Format("CSerial exception %s source: %s\nmessage : %s\nstack: %s",ex1->ToString(),ex1->Source,ex1->Message,ex1->StackTrace));
}

BOOL CSerial::Open_port(System::String ^  commPort)
{
	try {
		if (_serialPort->IsOpen){
			_serialPort->Close();
		}
		Configure_port(commPort);
		_serialPort->Open();
	} catch ( Exception^ ex1) {
		logException(ex1);
	}

	return true;
}
//*****************************************************

BOOL CSerial::Configure_port(System::String ^  commPort)
{

	 _serialPort = gcnew SerialPort();

	// Allow the user to set the appropriate properties.
	_serialPort->PortName = commPort;
	_serialPort-> BaudRate = 9600;
	_serialPort->Parity =  Parity::None;
	_serialPort->DataBits =  8;
	_serialPort->StopBits =  StopBits::One  ;  
	_serialPort->Handshake =  Handshake::None;

	// Set the read/write timeouts
	_serialPort->ReadTimeout = GBSerialReadTotalTimeoutConstant;
	_serialPort->WriteTimeout = GBSerialReadTotalTimeoutConstant;



	//COMMTIMEOUTS touts;

 //   if (! GetCommTimeouts(hComm, &touts) )	{
	//	MessageBox(NULL,"GetCommTimeout Error","Error",MB_OK+MB_ICONERROR);
	//	CloseHandle(hComm);
	//	return false;
	//}

	//touts.ReadTotalTimeoutConstant = GBSerialReadTotalTimeoutConstant;
	//touts.ReadIntervalTimeout = GBReadIntervalTimeout;
 //   if (! SetCommTimeouts(hComm, &touts) )	{
	//	MessageBox(NULL,"SetCommTimeout Error","Error",MB_OK+MB_ICONERROR);
	//	CloseHandle(hComm);
	//	return false;
	//}

 return true;
}
//**************************************************
/*
BOOL CSerial::Write_port(void)
{
	try {
	} catch ( Exception^ ex1) {
		logException(ex1);
	}

 iBytesWritten=0;
 if(WriteFile(hComm,&Byte2Write,1,&iBytesWritten,NULL)==0)
 return false;
 else return true;
}*/

//***************************************************

BOOL CSerial::Read_port( array<Byte>^* buffer,   int count, int* amt)
{
	BOOL res = 0;
	String ^ resS;
	*amt = 0;
	try {
//		*amt = _serialPort->Read(buffer,0,count);
		_serialPort->DiscardInBuffer();
		resS = _serialPort->ReadTo("|||");
		array<Char>^charAr = resS->ToCharArray();
		*amt = resS->Length;
		Array::Resize(*buffer,resS->Length);
		for (int i1 = 0; i1 < resS->Length; ++ i1) {
			(*buffer)->SetValue( (Byte)(charAr[i1]) ,i1);
		}
		res = 1;
	} catch ( Exception^ ex1) {
		logException(ex1);
	}
//	return ReadFile (hComm, lpBuffer, len, dwBytesTransferred, 0);
 // return value will not actually be used and does not make much sense anyhow  ????
	return res;
}

//**************************************************

BOOL CSerial::Close_port(void)
{
	try {
		if (_serialPort->IsOpen){
			_serialPort->Close();
		}
	} catch ( Exception^ ex1) {
		logException(ex1);
	}
 return true;
}
//*************************************************
// main function 
