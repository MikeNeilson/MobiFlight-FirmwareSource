#pragma once

namespace mobiflight
{
    using size_t = int;

    template <bool B, class T>
    struct enable_if {
    };

    template <typename T>
    struct enable_if<true, T> {
        typedef T type;
    };

    template <typename T1, typename T2>
    struct is_same {
        static constexpr bool value = false;
    };

    template <typename T>
    struct is_same<T, T> {
        static constexpr bool value = true;
    };
};
