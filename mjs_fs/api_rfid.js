let MFRC522 = {
    _create: ffi('void *mgos_mfrc522_create(int, int)'),
    _init: ffi('void mgos_mfrc522_init(void *)'),
    _dump2serial: ffi('void mgos_mfrc522_dump2serial(void *)'),
    _isnewcardpresent: ffi('bool mgos_mfrc522_isnewcardpresent(void *)'),
    _readuic: ffi('uint8_t mgos_mfrc522_readuic(void *)'),

    create: function(pin1,pin2) {
        let obj = Object.create(MFRC522._proto);
        obj.rfid = MFRC522._create(pin1,pin2);
        return obj;
      },

      
    _proto: {
        init: function() {
            return MFRC522._init(this.rfid);
        },
        dump2serial: function() {
            return MFRC522._dump2serial(this.rfid);
        },
        isnewcardpresent: function() {
            return MFRC522.readuic(this.rfid);
        },
    },
};