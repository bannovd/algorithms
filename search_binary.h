#ifndef SEARCH_BINARY_H
#define SEARCH_BINARY_H

#include <iterator>
#include <algorithm>


namespace algorithms
{
    template<class Iterator, typename T>
    static long search_binary(Iterator begin, Iterator end, T key)
    {
        auto left = begin;
        auto right = end;
        Iterator middle;
        while(true)
        {
            middle = left + std::distance(left, right) / 2;
            if(key < *middle)
                right = middle - 1;
            else if (key > *middle)
                left = middle + 1;
            else
                return std::distance(begin, middle);

            if (left > right) return -1;
        }
    }

    template <class Container, typename T>
    static long search_binary(Container &container, T key)
    {
        return search_binary(container.begin(), container.end(), key);
    }
}

#endif // SEARCH_BINARY_H
