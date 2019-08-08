#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <iterator>


namespace utilities
{
    template<class Iterator>
    static void print_vec(const Iterator begin, const Iterator end)
    {
        assert(begin < end);
        for (auto i = begin; i < end; ++i)
            std::cout << *i << " ";
        std::cout << "..." << std::endl;
    }

    template<class Container>
    static void print_vec(const Container &container)
    {
        print_vec(container.begin(), container.end());
    }

    template<class Container>
    static void print_vec(const Container &container, long count)
    {
        assert(count <= std::distance(container.begin(), container.end()));
        print_vec(container.begin(), container.begin() + count);
    }
}

#endif // UTILITIES_H
