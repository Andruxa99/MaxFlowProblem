#pragma once
#include <algorithm>
#include <stdexcept>
using namespace std;

template<class T> class myArray
{
public:
    explicit myArray(size_t size, T value = 0);
    myArray() {};
    ~myArray();
    myArray<T>(const myArray<T>& a);

    size_t getSize() const { return size; };
    void fill(T value);

    T operator [](size_t index) const;
    T& operator [](size_t index);
    myArray<T>& operator=(const myArray<T>& a);
private:
    T* arr;
    size_t size;

    void swap(myArray<T>& a);
};

