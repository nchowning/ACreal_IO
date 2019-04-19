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
    void setCardPresent();
    void setCardAbsent();
    void getUID(byte* uid);

private:
    byte card;
    int readernum;
};

#endif
