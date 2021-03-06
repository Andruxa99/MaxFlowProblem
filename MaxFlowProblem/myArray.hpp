#pragma once
#include "myArray.h"
#include <algorithm>

template<class T>
myArray<T>::myArray(size_t size, T value)
    : size(size), arr(new T[size]) {
    fill(value);
}

template<class T>
myArray<T>::~myArray() 
{ 
    delete[] arr; 
}

template<class T>
myArray<T>::myArray(const myArray<T>& a)
    :size(a.size), arr(new T[a.size])
{
    for (size_t i = 0; i < size; i++)
        arr[i] = a[i];
}

template<class T>
size_t myArray<T>::get_size() const
{
    return size;
}

template<class T>
void myArray<T>::fill(T value)
{
    std::fill(arr, arr + size, value);
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

template<class T>
void myArray<T>::swap(myArray<T>& a)
{
    std::swap(size, a.size);
    std::swap(arr, a.arr);
}
