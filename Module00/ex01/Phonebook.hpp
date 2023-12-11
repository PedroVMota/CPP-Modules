#include "Contact.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>


class Phonebook
{
public:
    Phonebook();
    void prompt();
    void add();
    void search();
    void add_test_data();

private:
    Contact _contact[8];
    int _index;
};
