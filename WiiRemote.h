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

	bool setLEDs(bool led1, bool led2, bool led3, bool led4);

};

}

#endif

