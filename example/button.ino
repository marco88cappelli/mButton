#include <mButton.h>

mButton	pulsante;


void setup() {
	Serial.begin(9600);
	Serial.println("TEST");
	pulsante.begin(7, 25, true, release, press, NULL);
}

void press() {
	Serial.print(millis());
	Serial.println(" - Pulsante Premuto");

}

void release(long long t) {
	Serial.print(millis());
	Serial.print(" - Rilasciato. Pressione durata: ");
	Serial.print (((int)t)/1000);
	Serial.println(" sec");
}


// the loop function runs over and over again until power down or reset
void loop() {
	pulsante.checkStateButton();
}
