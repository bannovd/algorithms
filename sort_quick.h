#ifndef SORT_QUICK_LOMUTO_H
#define SORT_QUICK_LOMUTO_H

#include <algorithm>
#include <iostream>


namespace algorithms
{
    template<class Iterator>
    static Iterator partition(Iterator begin, Iterator end)
    {
        Iterator i = begin;
        Iterator j = end;
        auto pivot = *begin;

        while (i < j)
        {
            while ((i <= j) && *i <= pivot)
                i++;

            while((i <= j) && *j > pivot)
                j--;

            if (i < j)
                std::swap(*i, *j);
        }
        std::swap(*begin, *j);
        return j;
    }

    template<class Iterator>
    static void sort_quick(Iterator begin, Iterator end)
    {
        if(begin < end)
        {
            auto pivot = partition(begin, end);
            sort_quick(begin, pivot - 1);
            sort_quick(pivot + 1, end);
        }
    }

    template<class Container>
    static void sort_quick(Container &container)
    {
        sort_quick(container.begin(), container.end() - 1);
    }
}

#endif // SORT_QUICK_LOMUTO_H
