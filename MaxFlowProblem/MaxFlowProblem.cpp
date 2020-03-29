#include <iostream>
//#include "matrix_ff.h"
#include "adjList_ff.h"
//#include "matrix_io.h"
#include "adjList_io.h"

int main()
{
    //matrix<int> graph;
    graph g;
    int v, e, source, dest;
    
    //matrix_io io("input.txt", "output.txt");
    adjList_io io("input.txt", "output.txt");
    io.read(g, v, e, source, dest);

    adjList_ff adjList_ff(g, v, e, source, dest);
    io.write(adjList_ff.solve());
    
    return 0;
}
