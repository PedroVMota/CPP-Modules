#include "Serialize.hpp"

uintptr_t Serialize::serialize(void *ptr) { return reinterpret_cast<uintptr_t>(ptr); }
void *Serialize::Deserialize(   uintptr_t raw) { return reinterpret_cast<void *>(raw);}

/*

Memory Manipulation: When you need to treat a block of memory as a different type temporarily, such as when serializing or deserializing data.

Interfacing with C Code: When working with C libraries or APIs that use raw memory or have different type conventions, reinterpret_cast can help bridge the gap between C and C++ types.

Low-Level Optimization: In performance-critical code where you need to optimize memory usage or access, reinterpret_cast can provide more control over how data is represented in memory.

Data Structure Compatibility: When dealing with different data structures that share a similar memory layout, such as structs or classes with the same member variables in different orders or with different padding.

Type Punning: Type punning refers to treating memory occupied by one type as if it were another type. While type punning is generally considered unsafe, reinterpret_cast can be used in certain cases where you need to reinterpret the bits of a value without violating strict aliasing rules

*/