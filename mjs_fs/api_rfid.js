let MFRC522 = {
    _create: ffi('void *mgos_mfrc522_create()'),
    _init: ffi('void *mgos_mfrc522_init(void *)'),

    create: function() {
        let obj = Object.create(MFRC522._proto);
        obj.rfid = MFRC522._create(21,22);
        return obj;
      },

      
    _proto: {
        init: function() {
            return MFRC522._init(this.rfid);
        },
    },
};