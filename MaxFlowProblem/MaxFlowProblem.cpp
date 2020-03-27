#include <iostream>
#include "matrix_ff.h"

int main()
{
    int v, e, source, dest;
    cin >> v >> e >> source >> dest;

    matrix<int> matrix(v + 1, v + 1);
    for (int i = 0, v1, v2, cap; i < e; i++) {
        cin >> v1 >> v2 >> cap;
        matrix[v1][v2] = cap;
    }
    matrix_ff ff(matrix, v, e, source, dest);
    cout << ff.solve();

    return 0;
}
