#include <iostream>
#include "matrix_ff.h"
#include "matrix_io.h"

int main()
{
    matrix<int> graph;
    int v, e, source, dest;
    
    matrix_io io("input.txt", "output.txt");
    io.read(graph, v, e, source, dest);

    matrix_ff matrix_ff(graph, v, e, source, dest);
    io.write(matrix_ff.solve());
    
    return 0;
}
