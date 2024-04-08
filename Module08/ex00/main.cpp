#include "easyfind.hpp"

int main() {
    std::vector<char> vec;
    vec.push_back('p');
    vec.push_back('u');
    vec.push_back('t');
    vec.push_back('a');
    vec.push_back('s');

    try {
        std::vector<char>::iterator result = easyfind(vec, '6');
        std::cout << "Value found at index: " << std::distance(vec.begin(), result) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}