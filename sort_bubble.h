#ifndef SORT_BUBBLE_H
#define SORT_BUBBLE_H

#include <utility>
#include <assert.h>


namespace algorithms
{
    template<class Iterator>
    static void sort_bubble(Iterator begin, Iterator end)
    {
        assert(begin < end);

        bool swapped;
        do
        {
            swapped = false;
            for (auto i = begin + 1; i < end; ++i)
            {
                if (*(i - 1) > *i)
                {
                    std::swap(*(i - 1), *i);
                    swapped = true;
                }
            }
        }while(swapped);
    }

    template<class Container>
    static void sort_bubble(Container &container)
    {
        sort_bubble(container.begin(), container.end());
    }
}

#endif // SORT_BUBBLE_H
