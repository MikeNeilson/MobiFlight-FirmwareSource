#pragma once
#include <buttons.h>
#include <gpiod.h>
#include <iostream>

namespace mobiflight
{
    namespace devices
    {
        class Button
        {
        private:
            const gpiod_chip *_chip;
            gpiod_line       *_line;
            const char       *_name;
            uint8_t           _state = 1;

        public:
            Button(const gpiod_chip *chip, gpiod_line *line, const char *name)
            {
                _chip = chip;
                _line = line;
                _name = name;
            }
            ~Button()
            {
                gpiod_line_release(_line);
            }

            template <typename Director>
            void update(Director &director)
            {
                std::cout << "button upate" << std::endl;
                uint8_t newState = (uint8_t)gpiod_line_get_value(_line);
                std::cout << " button (" << _name << ") -> '" << newState * 2 << "'" << std::endl;
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
                director.send(button_event(event_type, -1, _name));
            }

            const char *name() { return _name; }
        };
    }
}