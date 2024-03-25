#include "Serialize.hpp"
#include <iostream>
int main(void)
{

    void *ptr = new int(42);

    std::cout << "Original: " << ptr << std::endl;
    uintptr_t raw = Serialize::serialize(ptr);
    std::cout << "Serialized: " << raw << std::endl;
    void *deserialized = Serialize::Deserialize(raw);
    std::cout << "Deserialized: " << deserialized << std::endl;

    delete static_cast<int *>(deserialized);
    
}