#include <MFRC522.h>
#include <SPI.h>

#define SS_PIN 53
#define RST_PIN 5         

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
	Serial.begin(9600);
	SPI.begin();
	mfrc522.PCD_Init();
}

void loop() {
	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

	// Dump info about the card
	mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
