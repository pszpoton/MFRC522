let MFRC522 = {
    _create: ffi('void *mgos_mfrc522_create()'),
    _init: ffi('void *mgos_mfrc522_init(void *,int,int)'),

    create: function(rst, res) {
        let obj = Object.create(MFRC522._proto);
        obj.rfid = MFRC522._create();
        return obj;
      },

      
    _proto: {
        init: function(sel_pin, rst_pin) {
            return MFRC522._init(this.rfid, sel_pin, rst_pin);
        },
    },
};