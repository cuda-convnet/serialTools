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


public ref class CSerial
{
public:
 CSerial();
 virtual ~CSerial();

static SerialPort^ _serialPort;

 BOOL Open_port(System::String ^  commPort);
// BOOL Write_port(void);
 BOOL Read_port( array<Byte>^  , int );
 BOOL Close_port(void);

private:

// HANDLE hComm;
// DCB      m_dcb;
// COMMTIMEOUTS m_CommTimeouts;
 BOOL     m_bPortReady;
 BOOL     bWriteRC;
 BOOL     bReadRC;
 DWORD iBytesWritten;
 DWORD iBytesRead;
 DWORD dwBytesRead;

 BOOL Configure_port(System::String ^  commPort);
 void logException(Exception^ ex1);
} ;