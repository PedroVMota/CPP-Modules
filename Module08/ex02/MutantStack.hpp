#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

template <class Type>
class MutantStack : public std::stack<Type, std::list<Type> >
{
public:
    MutantStack(): std::stack<Type, std::list<Type> >(){};
    ~MutantStack(){};
    MutantStack(MutantStack<Type> const &o) : std::stack<Type, std::list<Type> >(o) { *this = o; }

    MutantStack &operator=(MutantStack<Type> const &ref)
    {
        if(this == &ref)
            return *this;
        this->c = ref.c;
        return *this;
    }


    typedef typename std::list<Type>::iterator iterator;
    typedef typename std::list<Type>::const_iterator const_iterator;
    typedef typename std::list<Type>::reverse_iterator reverse_iterator;
    typedef typename std::list<Type>::const_reverse_iterator const_reverse_iterator;

    
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator cbegin() const { return this->c.begin(); }
    const_iterator cend() const { return this->c.end(); }
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
    const_reverse_iterator crbegin() const { return this->c.rbegin(); }
    const_reverse_iterator crend() const { return this->c.rend(); }
};

template <class Type>
std::ostream& operator<<(std::ostream& os, const MutantStack<Type>& stack) {
    for (typename MutantStack<Type>::const_iterator it = stack.cbegin(); it != stack.cend(); ++it) {
        os << *it << ' ';
    }
    return os;
}