#include "UndirectedWeightedGraph.h"
#include <fstream>
#include <sstream>
#include <limits>

int main() {
    // Read Board.txt file
    ifstream file("Board.txt");
    if (!file.is_open()) {
        cout << "Failed to open Board.txt." << endl;
        return 1;
    }

    vector<vector<int>> board;
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        vector<int> row;
        int value;
        while (iss >> value) {
            row.push_back(value);
        }
        board.push_back(row);
    }
    file.close();

    // Convert Board.txt to undirected weighted graph
    int numRows = board.size();
    int numCols = board[0].size();
    int numVertices = numRows * numCols;
    UndirectedWeightedGraph graph(numVertices);

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            int currentVertex = row * numCols + col;
            int currentValue = board[row][col];

            // Connect to the right neighbor
            if (col + 1 < numCols && board[row][col + 1] != -1) {
                int rightNeighbor = row * numCols + (col + 1);
                int rightWeight = (board[row][col + 1] == -1) ? numeric_limits<int>::max() : 1;
                graph.addEdge({ currentVertex, rightNeighbor, rightWeight });
            }

            // Connect to the bottom neighbor
            if (row + 1 < numRows && board[row + 1][col] != -1) {
                int bottomNeighbor = (row + 1) * numCols + col;
                int bottomWeight = (board[row + 1][col] == -1) ? numeric_limits<int>::max() : 1;
                graph.addEdge({ currentVertex, bottomNeighbor, bottomWeight });
            }
        }
    }

    // Perform BFS and DFS on the graph
    cout << "BFS: ";
    graph.BFS();
    cout << endl;
    cout << "DFS: ";
    graph.DFS();
    cout << endl;

    return 0;
}
