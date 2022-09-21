#pragma once

#ifdef ARDUINO
#include <Arduino.h>
#endif

#include "meta_lib.h"
#include "tuple.h"
#include "devices.h"
#include "buttons.h"

namespace mobiflight
{

    template <size_t i = 0, typename T, typename Messenger>
    typename enable_if<i == tuple_size<T>::size, void>::type
    update_modules(T &modules, Messenger &messenger)
    {
    }

    template <size_t i = 0, typename T, typename Messenger>
    typename enable_if<i != tuple_size<T>::size, void>::type
    update_modules(T &modules, Messenger &messenger)
    {
        get<i>(modules).update(messenger);
        update_modules<i + 1>(modules, messenger);
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
            update_modules(modules, messenger);
        }

        template <typename T>
        T &get_module()
        {
            return get<T>(modules);
        }
    };
};