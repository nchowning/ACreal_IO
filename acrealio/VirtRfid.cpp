#include "Arduino.h"
#include "VirtRfid.h"

VirtRfid::VirtRfid()
{
    card = 0;
    readernum = 1;
}

void VirtRfid::setPins(int sensor, HardwareSerial* serialid)
{
    if (sensor == R1_DET)
        readernum = 1;
    else
        readernum = 2;
}

void VirtRfid::read()
{
}

void VirtRfid::update()
{
}

byte VirtRfid::isCardPresent()
{
    return card;
}

void VirtRfid::setCardPresent()
{
    // This gets triggered in Reader.cpp when the unused keypad key is pressed
    card = 1;
}

void VirtRfid::setCardAbsent()
{
    // This gets triggered in Reader.cpp when the unused keypad key is pressed
    card = 0;
}

void VirtRfid::getUID(byte* uid)
{
    // TODO Read card IDs from pinouts file
    if (readernum == 1)
        // Player 1 Card
        memcpy(uid, (const byte [8]){0x01, 0x2E, 0x48, 0xC2, 0x3C, 0x97, 0xBA, 0x94}, 8);
    else
        // Player 2 Card
        memcpy(uid, (const byte [8]){0xE0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 8);
}
