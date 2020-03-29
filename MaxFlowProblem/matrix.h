#pragma once
#include "myArray.cpp"

template<class T> class matrix
{
public:
    explicit matrix(size_t n = 0, size_t m = 0, T value = 0);
    matrix<T>(const matrix<T>& a);
    ~matrix<T>();

    size_t getXSize() const { return n; };
    size_t getYSize() const { return m; };
    void fill(T value);

    myArray<T> operator [](size_t index) const;
    myArray<T>& operator [](size_t index);
    matrix<T>& operator=(const matrix<T>& a);
private:
    myArray<T>* arr;
    size_t n, m;

    void swap(matrix<T>& a);
};

