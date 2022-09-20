/* #pragma once
#include <functional>

    namespace mobiflight
{
    typedef std::function<void(uint8_t, uint8_t, const char *)> buttonEvent;

    class IMobiInput
    {
    public:
        virtual void update() = 0;
        virtual void attachHandler();
    };
};
* /