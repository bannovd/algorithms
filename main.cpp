#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <limits.h>
#include "algorithms.h"
#include "utilities.h"


const std::vector<unsigned long> get_random_vector(std::vector<unsigned long>::size_type size)
{
    std::vector<unsigned long> vec(size);
    for (std::vector<unsigned long>::size_type i = 0; i < size; i++)
    {
        vec[i] = i;
    }
    srand(unsigned(time(nullptr)));
    random_shuffle(vec.begin(), vec.end());
    return vec;
}

int main()
{
    std::cout << "Sort algorithms\n" << "--\n";

    std::vector<unsigned long>::size_type size = 10000;
    const std::vector<unsigned long> vec_base = get_random_vector(size);
    std::cout << "base vector "<<"[0.." << size - 1 << "]: ";
    utilities::print_vec(vec_base, 10);

    //sort_bubble
    std::cout << "--\n" << "sort_bubble: ";
    std::vector<unsigned long> vec_sort_bubble(vec_base);

    auto begin = std::chrono::high_resolution_clock::now();
    algorithms::sort_bubble(vec_sort_bubble);
    auto end = std::chrono::high_resolution_clock::now();

    utilities::print_vec(vec_sort_bubble, 10);
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " micros" << std::endl;

    //sort_selection
    std::cout << "--\n" << "sort_selection: ";
    std::vector<unsigned long> vec_sort_selection(vec_base);

    begin = std::chrono::high_resolution_clock::now();
    algorithms::sort_selection(vec_sort_selection);
    end = std::chrono::high_resolution_clock::now();

    utilities::print_vec(vec_sort_selection, 10);
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " micros" << std::endl;

    //sort_insertion
    std::cout << "--\n" << "sort_insertion: ";
    std::vector<unsigned long> vec_sort_insertion(vec_base);

    begin = std::chrono::high_resolution_clock::now();
    algorithms::sort_insertion(vec_sort_insertion);
    end = std::chrono::high_resolution_clock::now();

    utilities::print_vec(vec_sort_insertion, 10);
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " micros" << std::endl;

    //sort_quick
    std::cout << "--\n" << "sort_quick: ";
    std::vector<unsigned long> vec_sort_quick(vec_base);

    begin = std::chrono::high_resolution_clock::now();
    algorithms::sort_quick(vec_sort_quick);
    end = std::chrono::high_resolution_clock::now();

    utilities::print_vec(vec_sort_quick, 10);
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " micros" << std::endl;

    //Search algorithms
    std::cout << "--\n" << "Search algorithms\n";
    unsigned long search_key = 94;

    //search_linear
    std::cout << "--\n" << "search_linear (unsorted container) ["<< search_key << "]: ";
    begin = std::chrono::high_resolution_clock::now();

    long search_index = algorithms::search_linear(vec_base, search_key);
    std::cout << "pos: " << search_index << " value: " << vec_base[search_index] << std::endl;
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanos" << std::endl;

    //search_binary
    std::cout << "--\n" << "search_binary (sorted container)  ["<< search_key << "]: ";

    begin = std::chrono::high_resolution_clock::now();
    search_index = algorithms::search_binary(vec_sort_quick, search_key);
    std::cout << "pos: " << search_index << " value: " << vec_sort_quick[search_index] << std::endl;
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanos" << std::endl;

    //search_interpolation
    std::cout << "--\n" << "search_interpolation (sorted container)  ["<< search_key << "]: ";

    begin = std::chrono::high_resolution_clock::now();
    search_index = algorithms::search_interpolation(vec_sort_quick, search_key);
    std::cout << "pos: " << search_index << " value: " << vec_sort_quick[search_index] << std::endl;
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanos" << std::endl;

    return 0;
}
