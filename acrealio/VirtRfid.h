#ifndef VIRTRFID_H
#define VIRTRFID_H

#include "Arduino.h"
#include "RfidModule.h"

class VirtRfid : public RfidModule
{
public:
    VirtRfid();
    void setPins(int sensor, HardwareSerial* serialid);
    void read();
    void update();
    byte isCardPresent();
    void setCardPresence();
    void getUID(byte* uid);

private:
    byte card;
    byte uid[8];
};

#endif
