#ifndef SORT_INSERTION_H
#define SORT_INSERTION_H

#include <assert.h>
#include <utility>


namespace algorithms
{
    template<class Iterator>
    static void sort_insertion(Iterator begin, Iterator end)
    {
        assert(begin < end);

        Iterator min;
        for (auto i = begin; i < end - 1; ++i)
        {
            min = i;
            for (auto j = i + 1; j < end; ++j)
            {
                if (*j < *min)
                    min = j;
            }

            if(*min < *i)
                std::swap(*min, *i);
        }
    }

    template<class Container>
    static void sort_insertion(Container &container)
    {
        sort_insertion(container.begin(), container.end());
    }
}

#endif // SORT_INSERTION_H
