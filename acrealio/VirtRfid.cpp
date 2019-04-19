#include "Arduino.h"
#include "VirtRfid.h"

VirtRfid::VirtRfid()
{
    card = 0;
    readcmd = false;
    pinset = false;

    uid[0] = 0xE0;
    uid[1] = 0x04;
    uid[2] = 0x00;
    uid[3] = 0x00;
    uid[4] = 0x00;
    uid[5] = 0x00;
    uid[6] = 0x00;
    uid[7] = 0x00;
}

void VirtRfid::setPins(int sensor, HardwareSerial* serialid)
{
    buttonPin = sensor;
    pinMode(buttonPin, INPUT);
    digitalWrite(buttonPin, HIGH);

    pinset = true;
}

void VirtRfid::read()
{
    readcmd = true;
}

void VirtRfid::update()
{
    if (!pinset)
        return;

    if (!readcmd)
        return;

    if (digitalRead(buttonPin))
        card = 0;
    else
        card = 1;

    readcmd = false;
}

byte VirtRfid::isCardPresent()
{
    return card;
}

void VirtRfid::setCardPresent()
{
    // This gets triggered in Reader.cpp when the unused keypad key is pressed
    setcard = true;
}

void VirtRfid::setCardAbsent()
{
    // This gets triggered in Reader.cpp when the unused keypad key is pressed
    setcard = false;
}

void VirtRfid::getUID(byte* uida)
{
    memcpy(uida, uid, 8);
}
