#pragma once
#include "devices.h"

namespace mobiflight
{
    template <int T = devices::kTypeNotSet>
    class Button
    {
    private:
        int pin;

    public:
        void update();

        static const int type = T;
    };
}
