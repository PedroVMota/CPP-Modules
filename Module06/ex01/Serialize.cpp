#include "Serialize.hpp"

uintptr_t Serialize::serialize(void *ptr) { return reinterpret_cast<uintptr_t>(ptr); }
void *Serialize::Deserialize(uintptr_t raw) { return reinterpret_cast<void *>(raw);}