#include <iostream>
#include "matrix_ff.h"
//#include "adjList_ff.h"
#include "matrix_io.h"
//#include "adjList_io.h"
#include "network_generator.h"

int main()
{
    matrix<int> graph;
    //graph g;
    int v, e, source, dest;
    cin >> v >> e >> source >> dest;

    /*matrix_io io("input.txt", "output.txt");
    adjList_io io("input.txt", "output.txt");
    io.read(g, v, e, source, dest);

    adjList_ff adjList_ff(g, v, e, source, dest);
    io.write(adjList_ff.solve());*/

    network_generator generator(v, e, source, dest);
    graph = generator.generate();
    for (size_t i = 1; i < v + 1; i++) {
        for (int j = 1; j < v + 1; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
