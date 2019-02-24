#include <Arduino.h>
#include "MFRC522.h"
#include "mgos.h"

MFRC522 mfrc522 = MFRC522(21, 22);

void setup() {
  //SPI.begin();   
 
  mfrc522.PCD_Init();
  mfrc522.PCD_DumpVersionToSerial();  
  LOG(LL_INFO, ("SPI initialized"));
 
}

// class TestClass {
//  public:
//   TestClass() {
//     printf("constructed\n");
//   }
//   ~TestClass() {
//     printf("destroyed %d\n", a_);
//   }
//   int a_ = 0;
// };

// void loop() {
//   static boolean value = 0;
//   digitalWrite(2, value);
//   printf("%s\r\n", (value == 0 ? "Tick" : "Tock"));
//   delay(500);
//   value = (value ? 0 : 1);
//   TestClass *foo = new TestClass();
//   foo->a_ = 1;
//   delete (foo);
// }