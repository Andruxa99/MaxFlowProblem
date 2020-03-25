#include <iostream>
#include "matrix.cpp"

void print(const myArray<int>& array);
void print(const matrix<int>& matrix);

int main()
{
    myArray<int> array(4, 2);
    print(array);
    
    matrix<int> matrix(5, 5, 5);
    print(matrix);
    matrix.fill(10);
    print(matrix);

    return 0;
}

void print(const myArray<int>& array)
{
    for (int i = 0; i < array.getSize(); i++)
        cout << array[i] << " ";
    cout << endl;
}

void print(const matrix<int>& matrix)
{
    for (int i = 0; i < matrix.getXSize(); i++) {
        for (int j = 0; j < matrix.getYSize(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
