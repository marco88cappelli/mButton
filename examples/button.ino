#include <mButton.h>

mButton	pulsante;


void setup() {
	Serial.begin(9600);
	Serial.println("TEST");
  //PIN: 7
  //DBOUNCE TIME: 25 ms
  //POINT OF FUNCTION RELEASE: typedef void(*funRelease)(long long tmp_pressButton);: void release(long long t)
  //POINT OF FUNCTION PRESS:typedef void(*funPress)();: void press()
  //POINT OF FUNCTION CHANGE STATE BUTTON typedef void(*funPress)(): NULL
  //In questo caso l'oggetto bottone non sarà reattivo al cambio di stato, ma solo alla pressione press e al rilascio release del pulsante
	pulsante.begin(7, 25, true, release, press, NULL);
  //Inizializzazione dell'oggetto pulsante
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
	//funzione di controllo degli stati del pulsante
  pulsante.checkStateButton();
}
