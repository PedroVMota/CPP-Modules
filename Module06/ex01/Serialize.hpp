#pragma once
#include <iostream>
#include <string>

typedef unsigned long long uintptr_t;


class Serialize
{
    public:
        static uintptr_t serialize(void *ptr);
        static void *Deserialize(uintptr_t raw);
    private:
        Serialize();
        ~Serialize();
        Serialize(const Serialize &src);
        Serialize &operator=(const Serialize &rhs);
    protected:

};