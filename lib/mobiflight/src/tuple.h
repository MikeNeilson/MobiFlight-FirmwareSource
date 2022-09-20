#pragma once

#include "meta_lib.h"

namespace mobiflight
{

    template <typename... T>
    struct tuple {
    };

    template <typename T, typename... Rest>
    struct tuple<T, Rest...> {
        T                       cur;
        tuple<Rest...>          rest;
        static constexpr size_t size = sizeof...(Rest) + 1;
        T                      &operator=(T &other)
        {
            cur = other;
            return cur;
        }
        T &operator=(T other)
        {
            cur = other;
            return cur;
        }
    };

    template <typename A>
    struct tuple_size {
        static constexpr size_t size = A::size;
    };

    template <size_t i, size_t position = 0, typename T, typename... Rest>
    typename enable_if<i == position, T &>::type get(tuple<T, Rest...> &the_tuple)
    {
        return the_tuple.cur;
    }

    template <size_t i, size_t position = 0, typename T, typename... Rest>
    typename enable_if<i != position, Rest &...>::type get(tuple<T, Rest...> &the_tuple)
    {
        return get<i, position + 1>(the_tuple.rest);
    };
};
