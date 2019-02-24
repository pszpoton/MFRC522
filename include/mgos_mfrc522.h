#include "MFRC522.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SS_PIN    21
#define RST_PIN   22
#define SIZE_BUFFER     18
#define MAX_SIZE_BLOCK  16
#define greenPin     12
#define redPin       32


MFRC522 *mgos_mfrc522_create();

void mgos_mfrc522_init(MFRC522 *rc5,int chipSelectPin ,int resetPowerDownPin);


#ifdef __cplusplus
}
#endif
