#include "mButton.h"

bool mButton::begin(int btPin, long long btDbTime = 25, bool btPulUp = 0, funRelease funButtonRelease = NULL, funPress funButtonPress = NULL, funPress funButtonChange = NULL) {
	oldState = (btPulUp == 1) ? 1 : 0;
	state = oldState;
	pin = btPin;
	dbTime = btDbTime;
	buttonChange = funButtonChange;
	buttonPress = funButtonPress;
	buttonRelease = funButtonRelease;
	pulUp = btPulUp;


	if (buttonChange == NULL && buttonPress == NULL && buttonRelease == NULL) {

		return false;
	}
	chekPress = false;

	pinMode(pin, (pulUp == 1) ? INPUT_PULLUP : INPUT);

	return true;

}

void mButton::checkStateButton() {

		if (!chekPress) {
			state = digitalRead(pin);
			delay(50);
			if (state != oldState) {
				time = millis();
				chekPress = !chekPress;
			}

		}

		if (chekPress) {
			if ((millis() - time) > dbTime) {
				state = digitalRead(pin);
				delay(50);
				if (oldState != state) {

					if (buttonChange != NULL) buttonChange();

					if (state == !pulUp) {
						timePress = millis();
						pressed = 1;
						if (buttonPress != NULL) buttonPress();
					}

					if ((state == pulUp) && (buttonPress != NULL)) {
						pressed = 0;
						buttonRelease((long long)(millis() - timePress));
					}
					oldState = state;
				}
				chekPress = false;
			}
		}
}
