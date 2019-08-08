#ifndef SEARCH_INTERPOLATION_H
#define SEARCH_INTERPOLATION_H

#include <iterator>
#include <iostream>


namespace algorithms
{
    template<class Iterator, typename T>
    static long search_interpolation(Iterator begin, Iterator end, T key)
    {
        auto i = begin;
        auto j = end;
        auto curr = begin;
        while (true)
        {
            curr = i + ((key - *i) * std::distance(i, j)) / (*j - *i);;
            if (*curr < key)
                i = curr + 1;
            else if (*curr > key)
                j = curr - 1;
            else
                return std::distance(begin, curr);

            if (*i == key)
                return std::distance(begin, i);
            if (*j == key)
                return  std::distance(begin, j);
        }

        return -1;
    }

    template <class Container, typename T>
    static long search_interpolation(Container &container, T key)
    {
        return search_interpolation(container.begin(), container.end() - 1, key);
    }
}

#endif // SEARCH_INTERPOLATION_H
