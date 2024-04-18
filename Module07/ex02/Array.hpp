#pragma once
#include <string>
#include <iostream>

template <class T>
class Array
{
private:
    T *_array;
    size_t _size;

public:
    Array() : _array(NULL), _size(0){};

    Array(const Array &other) : _array(NULL), _size(0)
    {
        _size = other._size;
        _array = new T[_size];
        for (size_t i = 0; i < _size; ++i)
            _array[i] = other._array[i];
    }

    Array(size_t size): _size(size), _array(NULL);
    {
        this->_array = new T[size];
    }

    Array &operator=(const Array &rhs)
    {
        if (this != &rhs)
        {
            delete[] _array; // Deallocate existing memory
            _size = rhs._size;
            _array = new T[_size];
            for (size_t i = 0; i < _size; ++i)
                _array[i] = rhs._array[i];
        }
        return *this;
    }

    T &operator[](size_t i)
    {
        if (!_array)
            throw std::runtime_error("The array is null");
        if (i >= _size)
            throw std::out_of_range("Index out of range");
        return _array[i];
    }

    size_t size() const
    {
        if (!_size)
            throw std::runtime_error("The array is null");
        return _size;
    }

    ~Array()
    {
        delete[] _array;
    }
};
