#ifndef DA_FIRST_PROJECT_GRAPH_H
#define DA_FIRST_PROJECT_GRAPH_H
#include <vector>
#include <list>
#include <queue>
#include <iostream>
using namespace std;

class Graph {
    struct Edge {
        int dest;
        int weight;
    };

    struct Node {
        list<Edge> adj;
        bool visited;
    };

    int n;
    bool hasDir;
    vector<Node> nodes;

public:
    Graph(int nodes, bool dir = false);
    void addEdge(int src, int dest, int weight = 1);
    void dfs(int v);
    void bfs(int v);
    };


#endif
