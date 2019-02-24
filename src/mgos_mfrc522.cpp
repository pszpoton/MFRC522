#include "mgos_mfrc522.h"

MFRC522 *mgos_mfrc522_create() {
  return new MFRC522();
}

void mgos_mfrc522_init(MFRC522 *rfid,int chipSelectPin ,int resetPowerDownPin)
 {
  if (rfid == nullptr) return;
  rfid->PCD_Init(chipSelectPin, resetPowerDownPin);
}