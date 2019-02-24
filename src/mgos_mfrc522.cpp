#include "mgos_mfrc522.h"

MFRC522 *mgos_mfrc522_create() {
  return new MFRC522(SS_PIN,RST_PIN);
}

void mgos_mfrc522_init(MFRC522 *rfid)
 {
  if (rfid == nullptr) return;
  rfid->PCD_Init();
}