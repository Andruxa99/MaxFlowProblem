#pragma once
#include <algorithm>
#include "myArray.h"

template<class T> class matrix
{
public:
    explicit matrix(size_t n = 0, size_t m = 0, T value = 0)
        : n(n), m(m), arr(new myArray<T>[n])
    {
        for (size_t i = 0; i < n; i++)
            arr[i] = myArray<T>(m, value);
    }

    matrix(const matrix<T>& a)
        :n(a.n), m(a.m), arr(new myArray<T>[a.n])
    {
        for (size_t i = 0; i < n; i++) {
            arr[i] = myArray<T>(m);
            for (size_t j = 0; j < m; j++)
                arr[i][j] = a[i][j];
        }
    }

    ~matrix() { delete[] arr; }

    size_t getXSize() const { return n; };

    size_t getYSize() const { return m; };

    void fill(T value)
    {
        for (size_t i = 0; i < n; i++)
            arr[i].fill(value);
    }

    myArray<T> operator[](size_t index) const { return arr[index]; }

    myArray<T>& operator[](size_t index){ return arr[index]; }

    matrix<T>& operator=(const matrix<T>& a)
    {
        if (&a != this)
            matrix<T>(a).swap(*this);
        return *this;
    }

private:
    myArray<T>* arr;
    size_t n, m;

    void swap(matrix<T>& a)
    {
        std::swap(n, a.n);
        std::swap(m, a.m);
        std::swap(arr, a.arr);
    }
};

