#pragma once

#include "stdafx.h"
//#include "iostream.h"
#using <System.dll>

using namespace System;
using namespace System::IO::Ports;
using namespace System::Threading;
using namespace System::Diagnostics;

//  PN 8. Nov 2005
//
//  code to access the serial port, copied from a MSDN sample
//
//


typedef bool   BOOL;
typedef long	DWORD;

#define GBSerialReadTotalTimeoutConstant  8000  
// must be bigger maximum possible delay between incoming messages

 
#define GBReadIntervalTimeout  500

// TODO sad but true. the hyper schicki micki .net does not support that feature, but even worse
// you can read under serialport.ReceivedBytesThreshold ... they rebuild into some nice featured mask called .net
// but do not know whatfor serial port really are used..

public ref class CSerial
{
public:
 CSerial();
 virtual ~CSerial();

static SerialPort^ _serialPort;

 BOOL Open_port(System::String ^  commPort);
// BOOL Write_port(void);
 BOOL Read_port( array<Byte>^*  , int, int* );
 BOOL Close_port(void);

private:

// HANDLE hComm;
// DCB      m_dcb;
// COMMTIMEOUTS m_CommTimeouts;
// BOOL     m_bPortReady;
// BOOL     bWriteRC;
// BOOL     bReadRC;
// DWORD iBytesWritten;
// DWORD iBytesRead;
// DWORD dwBytesRead;

 BOOL Configure_port(System::String ^  commPort);
 void logException(Exception^ ex1);
} ;