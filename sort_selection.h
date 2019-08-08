#ifndef SORT_SELECTION_H
#define SORT_SELECTION_H

#include <assert.h>
#include <utility>


namespace algorithms
{
    template<class Iterator>
    static void sort_selection(Iterator begin, Iterator end)
    {
        assert(begin < end);

        Iterator j;
        for (auto i = begin; i < end - 1; ++i)
        {
            j = i;
            while (j > begin && *(j - 1) > *j)
            {
                std::swap(*j, *(j - 1));
                --j;
            }
        }
    }

    template<class Container>
    static void sort_selection(Container &container)
    {
        sort_selection(container.begin(), container.end());
    }
}

#endif // SORT_SELECTION_H
