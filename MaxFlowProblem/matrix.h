#pragma once
#include "myArray.h"

template<class T> class matrix
{
public:
    explicit matrix(size_t n = 0, size_t m = 0, T value = 0);
    ~matrix();
    matrix(const matrix<T>& a);

    size_t get_x_size() const;
    size_t get_y_size() const;
    void fill(T value);

    myArray<T> operator[](size_t index) const;
    myArray<T>& operator[](size_t index);
    matrix<T>& operator=(const matrix<T>& a);

private:
    myArray<T>* arr;
    size_t n, m;

    void swap(matrix<T>& a);
};

#include "matrix.hpp"

