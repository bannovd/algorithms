#ifndef SEARCH_LINEAR_H
#define SEARCH_LINEAR_H


namespace algorithms
{
    template<class Iterator, typename T>
    static long search_linear(Iterator begin, Iterator end, T key)
    {
        long j = -1;
        for (auto i = begin; i < end; ++i)
        {
            ++j;
            if (*i == key) return j;
        }
        return j;
    }

    template <class Container, typename T>
    static long search_linear(Container &container, T key)
    {
        return search_linear(container.begin(), container.end(), key);
    }
}

#endif // SEARCH_LINEAR_H
