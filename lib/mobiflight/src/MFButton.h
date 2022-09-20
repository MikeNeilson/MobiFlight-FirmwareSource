//
// MFButton.h
//
// (C) MobiFlight Project 2022
//
/*
#pragma once

#include <function>

typedef std::function<void(uint8_t, uint8_t, const char *)> buttonEvent;

enum {
    btnOnPress,
    btnOnRelease,
};

/////////////////////////////////////////////////////////////////////
/// \class MFButton MFButton.h <MFButton.h>
class MFButton
{
public:
    // MFButton(uint8_t pin = 1, const char *name = "Button");

    static void  attachHandler(buttonEvent newHandler);
    virtual void update()               = 0;
    virtual void trigger(uint8_t state) = 0;
    virtual void triggerOnPress()       = 0;
    virtual void triggerOnRelease()     = 0;
};

// MFButton.h */