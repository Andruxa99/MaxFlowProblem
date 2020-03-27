#include "matrix.h"

template<class T> 
matrix<T>::matrix(size_t n, size_t m, T value)
    : n(n), m(m)
{
    arr = new myArray<T>[n];
    for (size_t i = 0; i < n; i++)
        arr[i] = myArray<T>(m, value);
}

template<class T> 
matrix<T>::matrix(const matrix<T>& a)
    :n(a.n), m(a.m), arr(new myArray<T>[a.n])
{
    for (size_t i = 0; i < n; i++) {
        arr[i] = myArray<T>(m);
        for (size_t j = 0; j < m; j++)
            arr[i][j] = a[i][j];
    }
}

template<class T>
matrix<T>::~matrix()
{
    delete[] arr;
}

template<class T>
void matrix<T>::fill(T value)
{
    for (size_t i = 0; i < n; i++)
        arr[i].fill(value);
}

template<class T>
void matrix<T>::swap(matrix<T>& a)
{
    std::swap(n, a.n);
    std::swap(m, a.m);
    std::swap(arr, a.arr);
}

template<class T>
myArray<T> matrix<T>::operator[](size_t index) const
{
    return arr[index];
}

template<class T>
myArray<T>& matrix<T>::operator[](size_t index)
{
    return arr[index];
}

template<class T>
matrix<T>& matrix<T>::operator=(const matrix<T>& a)
{
    if (&a != this)
        matrix<T>(a).swap(*this);
    return *this;
}
