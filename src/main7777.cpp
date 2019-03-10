#include <mgos_mfrc522.h>
#include "mgos.h"
#include <stdint.h>

MFRC522* mfrc522;

static void timer_cb(void *arg) {
   
    mgos_mfrc522_getblock(mfrc522,4);
}

enum mgos_app_init_result mgos_app_init(void) {
    printf("executing main program\n");
    printf("begin arudino\n");    
    mfrc522 = mgos_mfrc522_create(5,22); 
                                 // Initialize serial communications with the PC
    mfrc522->PCD_Init();                                              // Init MFRC522 card
    printf("Read personal data on a MIFARE PICC:");    //shows in serial that it is ready to read
    mfrc522->PCD_DumpVersionToSerial();  
    mgos_set_timer(400, true, timer_cb, NULL);
    return MGOS_APP_INIT_SUCCESS;
}

