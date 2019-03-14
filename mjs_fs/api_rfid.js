let MFRC522 = {
    _create: ffi('void *mgos_mfrc522_create(int, int)'),
    _init: ffi('void mgos_mfrc522_init(void *)'),
    _dump2serial: ffi('void mgos_mfrc522_dump2serial(void *)'),
    _isnewcardpresent: ffi('bool mgos_mfrc522_isnewcardpresent(void *)'),
    _getblock: ffi('bool *mgos_mfrc522_getblock(void *,int)'),
    _getcardvalue: ffi('int *mgos_mfrc522_getcardvalue(void *,int)'),

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
            return MFRC522._isnewcardpresent(this.rfid);
        },
        getblock: function(i) {
            return MFRC522._getblock(this.rfid,i);
        },
        getcardvalue: function(i) {
            return MFRC522._getcardvalue(this.rfid,i);
        },
    },
};