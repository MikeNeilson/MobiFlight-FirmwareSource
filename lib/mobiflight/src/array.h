#pragma once
#include "meta_lib.h"

namespace mobiflight
{
    template <typename T, size_t max>
    class array
    {
    private:
        T elements[max];

    public:
        T &operator[](const size_t index) noexcept
        {
            if (index < max) {
                return elements[index];
            } else {
                return nullptr;
            }
        }

        const T &operator[](const size_t &index) noexcept
        {
            if (index < max) {
                return elements[index];
            } else {
                return nullptr;
            }
        }
    };
}