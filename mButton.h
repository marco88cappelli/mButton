#pragma once

#ifndef MBUTTON.h
#define	MBUTTON.h

#if defined(ARDUINO) && ARDUINO>=100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif // defined(ARDUINO) && ARDUINO>=100

#include <stddef.h>

typedef void(*funRelease)(long long tmp_pressButton);
typedef void(*funPress)();

class mButton
{
private:
	int pin;	//Pin relativo al pulsante
	int oldState;
	int state;

	long long dbTime = 25;	//Tempo di debounce
	long long time = 0;
	long long timePress = 0;

	bool pulUp = 0;
	bool chekPress = 0;
	bool pressed = 0;

	funRelease buttonRelease;
	funPress buttonPress;
	funPress buttonChange;

public:
	bool begin(int btPin, long long btDbTime = 25, bool btPulUp = 0, funRelease funButtonRelease = NULL, funPress funButtonPress = NULL, funPress funButtonChange = NULL);
	void checkStateButton();
	bool isPressed() { return pressed; };
};
#endif // !MBUTTON.h
