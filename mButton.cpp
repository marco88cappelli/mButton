#include "mButton.h"

bool mButton::begin(int btPin, long long btDbTime = 25, bool btPulUp = 0, funRelease funButtonRelease = NULL, funPress funButtonPress = NULL, funPress funButtonChange = NULL) {
	oldState = (btPulUp == 1) ? 0 : 1;
	pin = btPin;
	dbTime = btDbTime;
	buttonChange = funButtonChange;
	buttonPress = funButtonPress;
	buttonRelease = funButtonRelease;
	pulUp = btPulUp;

#ifdef DEBUG_BUTTON
	Serial.println("\tDEBUG CLASS BUTTON:");
	Serial.print("\t\t-PIN:\t");
	Serial.println(pin);
	Serial.print("\t\t-OLD STATE:\t");
	Serial.println(oldState);
	Serial.print("\t\t-PULLUP:\t");
	Serial.println(pulUp);
	Serial.print("\t\t-DEBOUNCE TIME:\t");
	Serial.println(dbTime);
#endif // DEBUG_BUTTON


	if (buttonChange == NULL && buttonPress == NULL && buttonRelease == NULL) {
#ifdef DEBUG_BUTTON
		Serial.println("\tERRORE:");
		Serial.print("\t\t-Passare almeno una funzione");
#endif // DEBUG_BUTTON

		return false;
	}
	chekPress = false;

	pinMode(pin, (pulUp == 1) ? INPUT_PULLUP : INPUT);

	Serial.println("\tPulsante inizializzato Correttamente");

}

void mButton::checkStateButton() {
	int stateButton = digitalRead(pin);

	if ((!chekPress) && (oldState != stateButton)) {
		chekPress =!chekPress ;
		time = millis();
	}

	if (chekPress) {
		if ((millis() - time) > dbTime) {
			if (oldState != stateButton) {

				if (buttonChange != NULL) buttonChange();

				if (stateButton == !pulUp) {
					timePress = millis();
					if (buttonPress != NULL) buttonPress();
				}

				if ((stateButton == pulUp) && (buttonPress != NULL)) buttonRelease((long long)(millis() - timePress));

				oldState = stateButton;
			}

		}
		chekPress = false;
	}
}