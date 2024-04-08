#pragma once
#include <string>
#include <iostream>

template <typename T>
class Array{
    private:
        T *_array;
        size_t _size;
    public:
        Array();
        Array(size_t n){
            _array = new T[n];
            _size = n;
        }
        Array &operator=(Array const &rhs){
            if (this != &rhs){
                delete[] _array;
                _array = new T[rhs._size];
                for (size_t i = 0; i < rhs._size; i++){
                    _array[i] = rhs._array[i];
                }
                _size = rhs._size;
            }
            return *this;
        }
        T &operator[](size_t i){
            if (i >= _size){
                throw std::out_of_range("Index out of range");
            }
            return _array[i];
        }

        size_t size() const{
            return _size;
        }
        ~Array(){
            delete[] _array;
        }
};