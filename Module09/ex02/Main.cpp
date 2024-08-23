#include "PmergeMe.hpp"
#include <sstream>
#include <vector>
#include <iostream>
#include <iostream>
#include <vector>
#include "PmergeMe.hpp"

int main() {
    // Example usage with std::vector
    std::vector<double> data;
    data.push_back(38.9);
    data.push_back(27.4);
    data.push_back(43.3);
    data.push_back(3.9);
    data.push_back(9.7);
    data.push_back(82.1);
    data.push_back(10.4);
    data.push_back(14.5);
    data.push_back(19.2);

    try {
        PmergeMe<std::vector<double> > sorter(data);
        std::cout << "Sorted data: ";
        sorter.printContainer();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
