#include "Serialize.hpp"
#include <iostream>



/*

    Serialization in C++ refers to the process of converting data structures or objects into a format that can be easily stored or transmitted.
    This typically involves converting the object's state into a sequential representation of bytes.

    Deserialization, on the other hand, is the reverse process where the serialized data is converted back into its original data structure or object, reconstructing the object's state in memory.

    In memory, serialization involves converting the object's state into a byte stream,
    while deserialization involves reconstructing the object from the byte stream back into memory, effectively restoring its original state.
    These processes are often used for tasks such as data persistence, inter-process communication, and network communication in C++ applicationsz.
*/
int main(void)
{

        int *ptr = new int(42);

        std::cout << "Original: " << ptr << std::endl;
        uintptr_t raw = Serialize::serialize(ptr);
        std::cout << "Serialized: " << raw << std::endl;
        int *deserialized = (int *)Serialize::Deserialize(raw);
        std::cout << "Deserialized: " << deserialized << std::endl;

        delete (deserialized);
    
}