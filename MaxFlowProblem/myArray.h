#pragma once

template<class T> class myArray
{
public:
    explicit myArray(size_t size = 0, T value = 0);
    ~myArray();
    myArray(const myArray<T>& a);

    size_t get_size() const;
    void fill(T value);

    T operator[](size_t index) const;
    T& operator[](size_t index);
    myArray<T>& operator=(const myArray<T>& a);

private:
    T* arr;
    size_t size;

    void swap(myArray<T>& a);
};

#include "myArray.hpp"

