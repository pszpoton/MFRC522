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

const char *mgos_mfrc522_getblock(MFRC522 *rfid, int blockAddr)
 {
  if (rfid == nullptr){
    char a[1];
    return a;
  }
  if ( ! rfid->PICC_IsNewCardPresent()) 
  { char a[1];
    return a;
  }
  // Select one of the cards
  if ( ! rfid->PICC_ReadCardSerial()) 
  {
    char a[1];
    return a;
  }

  uint8_t buffer[18];
  rfid->PICC_getBlock(blockAddr,buffer);
  char card[128];
  uint8_t index = 0;

  for (uint8_t i = 0; i < 18; i++) {
      index += snprintf(&card[index], 128-index, "%d,", buffer[i]);
  }
  const char* cc=card;
  // printf("returning card value %s \n",cc);
  return cc;
}



