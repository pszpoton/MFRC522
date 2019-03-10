#include "MFRC522.h"

#ifdef __cplusplus
extern "C" {
#endif

MFRC522 *mgos_mfrc522_create(int chipSelectPin ,int resetPowerDownPin);

void mgos_mfrc522_init(MFRC522 *rc5);
void mgos_mfrc522_dump2serial(MFRC522 *rc5);
bool mgos_mfrc522_isnewcardpresent(MFRC522 *rc5);
bool mgos_mfrc522_readcardserial(MFRC522 *rc5);
char* mgos_mfrc522_getblock(MFRC522 *rc5,int blockAddr);


#ifdef __cplusplus
}
#endif
