#include "PmergeMe.hpp"


int main() {
    PmergeMe pmergeMe("4.2 3 2 1 5 11 22 99 8");
    pmergeMe.fordJohnsonSortDeque();
    pmergeMe.fordJohnsonSortMap();
    pmergeMe.fordJohnsonSortQueue();
    pmergeMe.fordJohnsonSortSet();
    return 0;
}