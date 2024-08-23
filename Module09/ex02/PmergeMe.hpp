#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

template<typename Container>
class PmergeMe {
private:
    Container& container;

    // Merge function to merge two halves
    void merge(typename Container::size_type left, typename Container::size_type middle, typename Container::size_type right);

    // Insertion sort for smaller subsequences
    void insertionSort(typename Container::size_type left, typename Container::size_type right);

    // Modified merge sort that uses insertion sort for small sizes
    void mergeInsertionSort(typename Container::size_type left, typename Container::size_type right);

public:
    // Constructor that initializes and sorts the container
    explicit PmergeMe(Container& container);

    // Utility function to print container elements
    void printContainer() const;
};

#include "PmergeMe.tpp"

#endif // PMERGEME_HPP
