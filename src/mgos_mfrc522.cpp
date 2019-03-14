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

bool mgos_mfrc522_getblock(MFRC522 *rfid, int blockAddr)
 {
  if (rfid == nullptr){
    return false;
  }
  if ( ! rfid->PICC_IsNewCardPresent()) 
  { 
    return false;
  }
  // Select one of the cards
  if ( ! rfid->PICC_ReadCardSerial()) 
  {

    return false;
  }

  return rfid->PICC_getBlock(blockAddr);
}

int mgos_mfrc522_getcardvalue(MFRC522 *rfid,int position){
  return rfid->card.value[position];
}



