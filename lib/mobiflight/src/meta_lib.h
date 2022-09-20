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
};
