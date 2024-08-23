#include "PmergeMe.hpp"

template<typename Container>
PmergeMe<Container>::PmergeMe(Container& container) : container(container) {
    if (container.empty()) {
        throw std::runtime_error("Container is empty");
    }
    std::clock_t start = std::clock();
    mergeInsertionSort(0, container.size() - 1);
    std::clock_t end = std::clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Sorting took " << elapsed << " seconds.\n";
}

template<typename Container>
void PmergeMe<Container>::merge(typename Container::size_type left, typename Container::size_type middle, typename Container::size_type right) {
    typename Container::size_type n1 = middle - left + 1;
    typename Container::size_type n2 = right - middle;

    std::vector<typename Container::value_type> leftVec(n1);
    std::vector<typename Container::value_type> rightVec(n2);

    std::copy(container.begin() + left, container.begin() + middle + 1, leftVec.begin());
    std::copy(container.begin() + middle + 1, container.begin() + right + 1, rightVec.begin());

    typename Container::size_type i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            container[k++] = leftVec[i++];
        } else {
            container[k++] = rightVec[j++];
        }
    }

    std::copy(leftVec.begin() + i, leftVec.end(), container.begin() + k);
    std::copy(rightVec.begin() + j, rightVec.end(), container.begin() + k);
}

template<typename Container>
void PmergeMe<Container>::insertionSort(typename Container::size_type left, typename Container::size_type right) {
    for (typename Container::size_type i = left + 1; i <= right; ++i) {
        typename Container::value_type key = container[i];
        typename Container::size_type j = i;
        while (j > left && container[j - 1] > key) {
            container[j] = container[j - 1];
            --j;
        }
        container[j] = key;
    }
}

template<typename Container>
void PmergeMe<Container>::mergeInsertionSort(typename Container::size_type left, typename Container::size_type right) {
    if (left < right) {
        if (right - left + 1 <= 10) {
            insertionSort(left, right);
        } else {
            typename Container::size_type middle = left + (right - left) / 2;

            mergeInsertionSort(left, middle);
            mergeInsertionSort(middle + 1, right);

            merge(left, middle, right);
        }
    }
}

template<typename Container>
void PmergeMe<Container>::printContainer() const {
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}
