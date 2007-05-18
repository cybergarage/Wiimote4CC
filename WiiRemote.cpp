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

	setLEDs(false, false, false, false);

	unsigned char *outBuf = getOutputByteBuffer();

	clearOutputByteBuffer();
	outBuf[0] = 0x12;
	outBuf[1] = 0x00;
	outBuf[2] = 0x31;
	if (write(outBuf, 3) <= 0)
		return false;

	return true;
}

////////////////////////////////////////////////
//	setLEDs
////////////////////////////////////////////////

bool WiiRemote::setLEDs(bool led1, bool led2, bool led3, bool led4)
{
	unsigned char *outBuf = getOutputByteBuffer();

	clearOutputByteBuffer();
	outBuf[0] = 0x11;
	outBuf[1] = 0x00;
	if (led1)
		outBuf[1]  |= 0x10;
	if (led2)
		outBuf[1]  |= 0x20;
	if (led3)
		outBuf[1]  |= 0x40;
	if (led4)
		outBuf[1]  |= 0x80;
	if (write(outBuf, 2) <= 0)
		return false;

	return true;
}

