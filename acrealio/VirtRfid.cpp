#include "Arduino.h"
#include "VirtRfid.h"

VirtRfid::VirtRfid()
{
    card = 0;
    readcmd = false;
    cardscan = false;
}

void VirtRfid::setPins(int sensor, HardwareSerial* serialid)
{
}

void VirtRfid::read()
{
    readcmd = true;
}

void VirtRfid::update()
{
    if (!readcmd)
        return;

    if (cardscan)
    {
        card = 1;
        readcmd = false;
        cardscan = false;
    }
    else
    {
        card = 0;
        readcmd = false;
    }
}

byte VirtRfid::isCardPresent()
{
    return card;
}

void VirtRfid::setCardPresent()
{
    // This gets triggered in Reader.cpp when the unused keypad key is pressed
    cardscan = true;
}

void VirtRfid::getUID(byte* uid)
{
    01 2E 48 C2 3C 97 BA 94
    memcpy(uid, (const byte [8]){0x01, 0x2E, 0x48, 0xC2, 0x3C, 0x97, 0xBA, 0x94}, 8);
}
