#include <iostream>
#include "myArray.cpp"

void print(const myArray<int>& array);

int main()
{
    myArray<int> array(4, 2);
    print(array);
    array.fill(5);
    print(array);

    return 0;
}

void print(const myArray<int>& array)
{
    for (int i = 0; i < array.getSize(); i++)
        cout << array[i] << " ";
    cout << endl;
}
