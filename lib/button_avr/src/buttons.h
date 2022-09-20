#pragma once
#include "meta_lib.h"
#include "button.h"

namespace mobiflight
{
    namespace devices
    {
        template <size_t MAX, typename T = Button<kTypeButton>>
        class Buttons
        {
        private:
            T *buttons[MAX];

        public:
            void add(int pin, const char *name)
            {
            }

            void update()
            {
            }
        };
    }
}