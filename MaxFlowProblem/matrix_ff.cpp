#include "matrix_ff.h"
#include "flow_runner.h"

matrix_ff::matrix_ff(matrix_network network)
    :  ford_fulkerson(network), network(network.get_network()){}

std::string matrix_ff::get_name()
{
    return ford_fulkerson::get_name() + " (матрица смежности)";
}

int matrix_ff::find_max_flow(int curNode, int curFlow)
{
    if (curNode == networkParams.dest) return curFlow;
    visited[curNode] = true;
    for (int i = 1; i <= networkParams.numOfNodes; i++) {
        if (!visited[i] && network[curNode][i] > 0) {
            int maxFlow = find_max_flow(i, std::min(curFlow, network[curNode][i]));
            if (maxFlow > 0) {
                flow_runner::run_flow_in_matrix_network(curNode, i, maxFlow, network);
                return maxFlow;
            }
        }
    }
    return 0;
}
