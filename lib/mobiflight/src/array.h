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
        /*
        array()
        {
            for (size_t i = 0; i < max; i++) {
                elements[i] = nullptr;
            }
        }
        ~array()
        {
            for (size_t i = 0; i < max; i++) {
                delete element[i];
            }
        }*/

        T &operator[](const size_t index) noexcept
        {
            if (index < max) {
                return elements[index];
            } /*else {
                throw "access beyond array";
            }*/
        }

        const T &operator[](const size_t &index) const noexcept
        {
            if (index < max) {
                return elements[index];
            } /*else {
                throw "access beyond array";
            }*/
        }
    };

}