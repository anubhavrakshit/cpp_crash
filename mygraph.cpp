#include <unordered_map>
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::unordered_map;

class Graph {
    unordered_map<size_t, vector<int>> adjList;
    public:
    Graph() = default;
    void addEdge(size_t u, size_t v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void printGraph() {
        for (auto& [k, v]:adjList) {
           cout << "Vertex " << k << " Edges ";
           for (auto nbr : v) {
            cout << nbr << " ";
           }
           cout << std::endl;
        }
    }
};

int main() {
    Graph myGraph;
    myGraph.addEdge(1, 3);
    myGraph.addEdge(1, 7);
    myGraph.addEdge(1, 27);
    myGraph.printGraph();
    return 0;
}