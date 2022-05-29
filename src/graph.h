#ifndef DA_FIRST_PROJECT_GRAPH_H
#define DA_FIRST_PROJECT_GRAPH_H
#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include <limits.h>
#include "maxHeap.h"
#include <algorithm>
#include <stack>
#include "exceptions.h"

#define INF (INT_MAX/2)

using namespace std;

class Graph {
    struct Edge {
        int dest;
        int capacity;
        int residual;
        int duration;
    };

    struct Node {
        list<Edge> adj;
        bool visited;
        int parent;
        int lot;
    };

    unsigned n;
    bool hasDir;
    vector<Node> nodes;

public:
    Graph(unsigned nodes, bool dir = false);
    Graph();
    void addEdge(int src, int dest, int capacity, int duration);
    void dfs(int v);
    void bfs(int v);
    void ffbfs(int s, int t);
    unsigned getNumNodes();
    Node getNode(int i);
    void maximumCapacityPath(unsigned src);
    void maximumCapacity(unsigned groupSize, unsigned src, unsigned dest);
    stack<int> getPath(int src, int dest);
    };


#endif
