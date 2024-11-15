// Student Name: Reyaaz Birch
// Student Number: 56714270

// Question: Implement Prim's algorithm using ADT to find the minimum spanning tree with a time complexity of O(n^2).
// and the subsequent values represent combinations of (vertex, edge, and weight).
// The output of the code should list the minimum spanning tree paths.

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacencyMatrix;

public:
    Graph(int n) : numVertices(n), adjacencyMatrix(n, vector<int>(n, 0)) {}
    //represents an undirected graph using an adjacency matrix to store the edges' weights.
    void addEdge(int src, int dest, int weight) {
        adjacencyMatrix[src][dest] = weight;
        adjacencyMatrix[dest][src] = weight;
    }

    int findMinKey(vector<int>& key, vector<bool>& mstSet) {
        int minKey = INT_MAX;
        int minIndex;

        for (int v = 0; v < numVertices; ++v) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        return minIndex;
    }

    void printMST(vector<int>& parent) {
        cout << "Minimum Spanning Tree Paths:\n";
        for (int i = 1; i < numVertices; ++i) {
            cout << "Edge: " << parent[i] << " - " << i << " Weight: " << adjacencyMatrix[i][parent[i]] << endl;
        }
    }

    void primMST() {
        vector<int> parent(numVertices, -1); // Array to store constructed MST
        vector<int> key(numVertices, INT_MAX); // Key values used to pick minimum weight edge in cut
        vector<bool> mstSet(numVertices, false); // To represent set of vertices not yet included in MST

        key[0] = 0; // Make the first vertex the root of MST

        for (int count = 0; count < numVertices - 1; ++count) {
            int u = findMinKey(key, mstSet);
            mstSet[u] = true;

            for (int v = 0; v < numVertices; ++v) {
                if (adjacencyMatrix[u][v] && !mstSet[v] && adjacencyMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjacencyMatrix[u][v];
                }
            }
        }

        printMST(parent);
    }
};

int main() {
    string filePath = "C:\\data\\datatest2.txt";    // Add path for the code to read test data from a text file (datatest2.txt) located in the C:\data folder.
    ifstream inputFile(filePath);

    if (!inputFile) {
        cerr << "Error: Unable to open the input file." << endl;
        return 1;
    }

    int numVertices, numEdges;
    inputFile >> numVertices >> numEdges;

    Graph graph(numVertices);

    int src, dest, weight;
    for (int i = 0; i < numEdges; ++i) {
        inputFile >> src >> dest >> weight;
        graph.addEdge(src, dest, weight);
    }

    inputFile.close();

    graph.primMST();

    return 0;
}
