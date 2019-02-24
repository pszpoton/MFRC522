#include "mgos_mfrc522.h"

MFRC522 *mgos_mfrc522_create(int chipSelectPin ,int resetPowerDownPin) {
  SPI.begin();   
  return new MFRC522(chipSelectPin,resetPowerDownPin);
}

void mgos_mfrc522_init(MFRC522 *rfid)
 {
  if (rfid == nullptr) return;
  rfid->PCD_Init();
}