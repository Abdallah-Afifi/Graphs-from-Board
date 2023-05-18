#include "UndirectedWeightedGraph.h"

UndirectedWeightedGraph::UndirectedWeightedGraph(int count) {
    numberOfVertices = count;
    adjacencyList.resize(count);
}

void UndirectedWeightedGraph::addEdge(Edge edge) {
    adjacencyList[edge.source].emplace_back(edge.destination, edge.weight);
    adjacencyList[edge.destination].emplace_back(edge.source, edge.weight);
}

void UndirectedWeightedGraph::BFS() {
    vector<bool> visited(numberOfVertices, false);
    queue<int> queue;

    visited[0] = true;
    queue.push(0);

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        cout << vertex << " ";

        for (const auto& neighbor : adjacencyList[vertex]) {
            int neighborVertex = neighbor.first;
            if (!visited[neighborVertex]) {
                visited[neighborVertex] = true;
                queue.push(neighborVertex);
            }
        }
    }
}

void UndirectedWeightedGraph::DFS() {
    vector<bool> visited(numberOfVertices, false);

    for (int vertex = 0; vertex < numberOfVertices; ++vertex) {
        if (!visited[vertex]) {
            DFSRec(vertex, visited);
        }
    }
}

void UndirectedWeightedGraph::DFSRec(int vertex, vector<bool>& visited) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (const auto& neighbor : adjacencyList[vertex]) {
        int neighborVertex = neighbor.first;
        if (!visited[neighborVertex]) {
            DFSRec(neighborVertex, visited);
        }
    }
}
