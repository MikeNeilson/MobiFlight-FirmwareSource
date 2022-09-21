#pragma once
#include "devices.h"
#include "buttons.h"
#include <Arduino.h>

namespace mobiflight
{
    namespace devices
    {
        class Button
        {
        private:
            int         _pin;
            uint8_t     _state;
            const char *_name;

        public:
            Button(int pin, const char *name)
            {
                this->_pin   = pin;
                this->_name  = name;
                this->_state = 1;
                pinMode(_pin, INPUT_PULLUP); // set pin to input
            }
            template <typename Director>
            void update(Director &director)
            {
                uint8_t newState = (uint8_t)digitalRead(_pin);
                if (newState != _state) {
                    _state = newState;
                    trigger(_state, director);
                }
            }

            template <typename Director>
            void trigger(uint8_t state, Director &director)
            {
                using namespace devices;
                auto event_type = (_state == LOW) ? devices::btnOnPress : devices::btnOnRelease;
                director.send(button_event(event_type, _pin, _name));
            }
        };
    }
}
