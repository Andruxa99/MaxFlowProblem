#pragma once
#include <algorithm>

template<class T> class myArray
{
public:
    explicit myArray(size_t size = 0, T value = 0)
        : size(size), arr(new T[size]) {
        fill(value);
    }

    ~myArray() { delete[] arr; }

    myArray(const myArray<T>& a)
        :size(a.size), arr(new T[a.size])
    {
        for (int i = 0; i < size; i++)
            arr[i] = a[i];
    }

    size_t getSize() const { return size; };

    void fill(T value)
    {
        for (int i = 0; i < size; i++)
            arr[i] = value;
    }

    T operator[](size_t index) const { return arr[index]; }

    T& operator[](size_t index) { return arr[index]; }

    myArray<T>& operator=(const myArray<T>& a)
    {
        if (&a != this)
            myArray<T>(a).swap(*this);
        return *this;
    }

private:
    T* arr;
    size_t size;

    void swap(myArray<T>& a)
    {
        std::swap(size, a.size);
        std::swap(arr, a.arr);
    }
};

