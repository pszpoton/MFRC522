#include "mgos_mfrc522.h"


MFRC522 *mgos_mfrc522_create(int chipSelectPin ,int resetPowerDownPin) {
  SPI.begin();   
  return new MFRC522(chipSelectPin,resetPowerDownPin);
}

// static const struct mjs_c_struct_member uid_descr[] = {
//   {"size", offsetof(struct uid, size), MJS_STRUCT_FIELD_TYPE_INT, NULL},
//   {"uidByte", offsetof(struct uid, uidByte), MJS_STRUCT_FIELD_TYPE_UINT8_PTR, NULL},
//   {"sak", offsetof(struct uid, sak), MJS_STRUCT_FIELD_TYPE_DOUBLE, NULL},
//   {NULL, 0, MJS_STRUCT_FIELD_TYPE_INVALID, NULL},
// };

void mgos_mfrc522_init(MFRC522 *rfid)
 {
  if (rfid == nullptr) return;
  rfid->PCD_Init();
}

void mgos_mfrc522_dump2serial(MFRC522 *rfid)
 {
  if (rfid == nullptr) return;
  rfid->PCD_DumpVersionToSerial();
}

bool mgos_mfrc522_isnewcardpresent(MFRC522 *rfid)
 {
  if (rfid == nullptr) return false;
  return rfid->PICC_IsNewCardPresent();
}

bool mgos_mfrc522_readcardserial(MFRC522 *rfid)
 {
  if (rfid == nullptr) return false;
  return rfid->PICC_ReadCardSerial();
}

char* mgos_mfrc522_readuic(MFRC522 *rfid)
 {
  if (rfid == nullptr) return NULL;
  return rfid->PICC_getUID();
}



