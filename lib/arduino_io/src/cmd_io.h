#pragma once

#include <CmdMessenger.h>
struct Messenger {
    CmdMessenger &messenger;

    Messenger(CmdMessenger &messenger)
        : messenger(messenger) {}

    void send(mobiflight::devices::button_event &&event)
    {
        Serial.println("Button event");
    }

    void get_updates()
    {
        messenger.feedinSerialData();
    }
};