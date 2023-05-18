#ifndef UNDIRECTED_WEIGHTED_GRAPH_H
#define UNDIRECTED_WEIGHTED_GRAPH_H

#include <queue>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};

class UndirectedWeightedGraph {
private:
    int numberOfVertices;
    vector<vector<pair<int, int>>> adjacencyList;
    void DFSRec(int vertex, vector<bool>& visited);

public:
    UndirectedWeightedGraph(int count);
    void addEdge(Edge edge);
    void BFS(); // Breadth First Search
    void DFS(); // Depth First Search
};

#endif
