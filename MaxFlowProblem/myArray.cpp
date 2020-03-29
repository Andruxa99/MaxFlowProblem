#include "myArray.h"
#include <algorithm>
using namespace std;

template<class T>
myArray<T>::myArray(size_t size, T value)
    : size(size), arr(new T[size]) {
    fill(value);
}

template<class T>
myArray<T>::~myArray() {
    delete[] arr;
}

template<class T>
myArray<T>::myArray(const myArray<T>& a)
    :size(a.size), arr(new T[a.size])
{
    for (int i = 0; i < size; i++)
        arr[i] = a[i];
}

template<class T>
void myArray<T>::fill(T value)
{
    for (int i = 0; i < size; i++)
        arr[i] = value;
}

template<class T>
void myArray<T>::swap(myArray<T>& a)
{
    std::swap(size, a.size);
    std::swap(arr, a.arr);
}

template<class T>
T myArray<T>::operator[](size_t index) const
{
    return arr[index];
}

template<class T>
T& myArray<T>::operator[](size_t index)
{
    return arr[index];
}

template<class T>
myArray<T>& myArray<T>::operator=(const myArray<T>& a)
{
    if (&a != this)
        myArray<T>(a).swap(*this);
    return *this;
}
