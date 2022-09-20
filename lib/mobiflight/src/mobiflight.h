#pragma once

#ifdef ARDUINO
#include <Arduino.h>
#endif

#include "tuple.h"

namespace mobiflight
{

    template <size_t i = 0, typename T>
    typename enable_if<i == tuple_size<T>::size, void>::type
    update_modules(T &modules)
    {
    }

    template <size_t i = 0, typename T>
    typename enable_if<i != tuple_size<T>::size, void>::type
    update_modules(T &modules)
    {
        get<i>(modules).update();
        update_modules<i + 1>(modules);
    }

    template <class Messenger, class Config, class... Modules>
    class MobiFlight
    {
    private:
        using ModTuple = tuple<Modules...>;
        ModTuple modules;

        Messenger &messenger;

    public:
        MobiFlight(const Config &config, Messenger &messenger)
            : messenger(messenger)
        {
        }
        MobiFlight(const Config &config, Messenger &messenger, Modules &...modules)
            : messenger(messenger), modules(modules...)
        {
        }
        void update()
        {
            update_modules(modules);
        }

        template <typename T>
        T &get_module()
        {
            return get<T>(modules);
        }
    };
};