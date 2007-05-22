/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2003
*
*	File:	WiiRemote.cpp
*
******************************************************************/

#ifndef _CX3D_WIIREMOTE_H_
#define _CX3D_WIIREMOTE_H_

#include "UsbHID.h"

namespace CyberX3D {

class WiiRemote : public UsbHID
{

	static const int VENDER_ID;
	static const int PRODUCT_ID;

public:

	WiiRemote();
	virtual ~WiiRemote();

	////////////////////////////////////////////////
	//	Functions
	////////////////////////////////////////////////

	bool open();

	////////////////////////////////////////////////
	//	LED
	////////////////////////////////////////////////

	bool setLEDs(bool led1, bool led2, bool led3, bool led4);

	////////////////////////////////////////////////
	//	Button
	////////////////////////////////////////////////

	bool IsAPressed()
	{
		return IsButtonPressed(2, 0x08);
	}

	bool IsBPressed()
	{
		return IsButtonPressed(2, 0x04);
	}

	bool IsOnePressed()
	{
		return IsButtonPressed(2, 0x02);
	}

	bool IsTwoPressed()
	{
		return IsButtonPressed(2, 0x01);
	}

	bool IsLeftPressed()
	{
		return IsButtonPressed(1, 0x01);
	}

	bool IsRightPressed()
	{
		return IsButtonPressed(1, 0x02);
	}

	bool IsUpPressed()
	{
		return IsButtonPressed(1, 0x08);
	}

	bool IsDownPressed()
	{
		return IsButtonPressed(1, 0x04);
	}

	bool IsMinusPressed()
	{
		return IsButtonPressed(2, 0x10);
	}

	bool IsPlusPressed()
	{
		return IsButtonPressed(1, 0x10);
	}

	bool IsHomePressed()
	{
		return IsButtonPressed(2, 0x80);
	}

	////////////////////////////////////////////////
	//	Motion
	////////////////////////////////////////////////

	unsigned char getXMotion()
	{
		return getInputByte(3);
	}

	unsigned char getYMotion()
	{
		return getInputByte(4);
	}

	unsigned char getZMotion()
	{
		return getInputByte(5);
	}
};

}

#endif

