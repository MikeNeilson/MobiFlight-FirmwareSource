#pragma once
#include "meta_lib.h"
#include "array.h"
#include "devices.h"

namespace mobiflight
{
    namespace devices
    {
        template <size_t MAX, typename ButtonType, device_type dt = kTypeButton>
        class Buttons
        {
        private:
            array<ButtonType *, MAX> buttons;
            size_t                   last = -1;

        public:
            void add(ButtonType *button)
            {
                if (last + 1 == MAX) return;
                last++;
                buttons[last] = button;
            }

            template <typename Director>
            void update(Director &director)
            {
                if (last < 0) return; // nothing to update
                for (size_t i = 0; i <= last; i++) {
                    buttons[i]->update(director);
                }
            }
            // static constexpr mobiflight::device::device_type = dt;
        };

        enum button_event_type {
            btnOnPress,
            btnOnRelease
        };

        struct button_event {
            button_event_type event_type;
            uint8_t           pin;
            const char       *name;

            button_event(button_event_type event_type, uint8_t pin,
                         const char *name)
                : event_type(event_type), pin(pin), name(name) {}
        };
    }
}