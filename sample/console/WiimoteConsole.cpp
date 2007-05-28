/******************************************************************
*
*	Wiimote for C++
*
*	Copyright (C) Satoshi Konno 2007
*
*	File:	WiimoteConsole.cpp
*
******************************************************************/

#include <stdio.h>
#include <cybergarage/wii/Wiimote.h>

using namespace CyberGarage;

////////////////////////////////////////////////////////// 
//  main
////////////////////////////////////////////////////////// 

int main( int argc, char *argv[] )
{
	Wiimote *wiimote;

	wiimote = new Wiimote();
	if (wiimote->open() == false) {
		delete wiimote;
		printf("Could not find Wiimote !!");
		return 0;
	}

	do {
		wiimote->read();
		printf("\r%+d %+d %+d %s %s %s %s %s %s %s %s %s %s %s",
			(wiimote->getXMotion()-0x80),
			(wiimote->getYMotion()-0x80),
			(wiimote->getZMotion()-0x80),
			(wiimote->IsAPressed() ? "A" : " "),
			(wiimote->IsBPressed() ? "B" : " "),
			(wiimote->IsOnePressed() ? "1" : " "),
			(wiimote->IsTwoPressed() ? "2" : " "),
			(wiimote->IsUpPressed() ? "U" : " "),
			(wiimote->IsDownPressed() ? "D" : " "),
			(wiimote->IsLeftPressed() ? "L" : " "),
			(wiimote->IsRightPressed() ? "R" : " "),
			(wiimote->IsMinusPressed() ? "-" : " "),
			(wiimote->IsPlusPressed() ? "+" : " "),
			(wiimote->IsHomePressed() ? "H" : " ")
			);
		Sleep(100);
	} while (wiimote->IsHomePressed() == false);

	wiimote->close();

	delete wiimote;
	return 0;
}

