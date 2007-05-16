/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2003
*
*	File:	WiiRemote.cpp
*
******************************************************************/

#include "WiiRemote.h"

using namespace CyberX3D;

const int WiiRemote::VENDER_ID = 0x057E;
const int WiiRemote::PRODUCT_ID = 0x0306;

////////////////////////////////////////////////
//	Constructor
////////////////////////////////////////////////

WiiRemote::WiiRemote() 
{
}

////////////////////////////////////////////////
//	Destructor
////////////////////////////////////////////////

WiiRemote::~WiiRemote()
{
}

////////////////////////////////////////////////
//	open 
////////////////////////////////////////////////

bool WiiRemote::open()
{
	bool openRes = UsbHID::open(VENDER_ID, PRODUCT_ID);
	if (!openRes)
		return false;

	unsigned char *outBuf = getOutputByteBuffer();

	clearOutputByteBuffer();
	outBuf[0] = 0x11;
	outBuf[1] = 0x00;
	if (write(outBuf, 2) <= 0)
		return false;

	clearOutputByteBuffer();
	outBuf[0] = 0x12;
	outBuf[1] = 0x00;
	outBuf[2] = 0x31;
	if (write(outBuf, 3) <= 0)
		return false;

	return true;
}