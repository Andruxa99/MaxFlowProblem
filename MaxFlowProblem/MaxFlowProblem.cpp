#include <iostream>
#include "matrix_ff.h"
//#include "adjList_ff.h"
#include "matrix_io.h"
//#include "adjList_io.h"
#include "network_generator.h"

int main()
{
    matrix<int> graph;
    int v, e, source, dest;

    io io("paramsInput.txt", "networkInput.txt");
    io.read(v, e, source, dest);

    network_generator generator(v, e, source, dest);
    graph = generator.generate();

    io.write(v), io.write(e), io.write(source), io.write(dest);
    io.write(graph);

    matrix_io matrix_io("networkInput.txt", "output.txt");
    matrix_io.read(graph, v, e, source, dest);

    matrix_ff matrix_ff(graph, v, e, source, dest);
    matrix_io.write(matrix_ff.solve());
       
    return 0;
}
