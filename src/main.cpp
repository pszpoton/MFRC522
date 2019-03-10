/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 */

#include <Arduino.h>
#include <MFRC522.h>
 
const uint8_t resetPin = 22; // Reset pin
const uint8_t ssPin = 5;    // Slave select pin


void setup() {
  printf("setup\r\n");
  SPI.begin();   
  printf("after spi\r\n");
  MFRC522 mfrc522 =  MFRC522(ssPin, resetPin);
  printf("ckass\r\n");
  mfrc522.PCD_Init();
  mfrc522.PCD_DumpVersionToSerial();  
  //LOG(LL_INFO, ("SPI initialized"));
  printf("SPI initialized\r\n");

}


void loop() {
//   if ( ! mfrc522.PICC_IsNewCardPresent()) 
//   {
//     return;
//   }
//   // Select one of the cards
//   if ( ! mfrc522.PICC_ReadCardSerial()) 
//   {
//     return;
//   }
}