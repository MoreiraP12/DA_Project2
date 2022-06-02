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

#define INF (UINT32_MAX/2)

using namespace std;

class Graph {
    struct Edge {
        unsigned dest;
        unsigned capacity;
        unsigned duration;
        unsigned flow = 0;
    };

    struct Node {
        list<Edge> adj;
        bool visited;
        unsigned parent;
        unsigned lot;
        unsigned degree;

        unsigned latestArr;
        unsigned earliestArr;

    };

    bool hasDir;


public:
    unsigned n;
    vector<Node> nodes;
    Graph(unsigned nodes, bool dir = false);
    Graph();
    void addEdge(unsigned src, unsigned dest, unsigned capacity, unsigned duration);
    void dfs(unsigned v);
    void bfs(unsigned v);
    Node getNode(unsigned i);
    void maximumCapacityPath(unsigned src);
    unsigned getNumNodes();
    stack<unsigned> getPath(unsigned src, unsigned dest);
    unsigned cpm();
    unsigned cpmDelay();
    stack<unsigned> getNodesDelay(unsigned delay);


    int edmondsKarp(int s, int t);
    int ekbfs(int s, int t);
    bool ekbfs(Graph &graph, int s, int t);
};


#endif
