#ifndef DA_FIRST_PROJECT_GRAPH_H
#define DA_FIRST_PROJECT_GRAPH_H
#include <vector>
#include <list>
#include <queue>
#include <iostream>
using namespace std;

class Graph {
    struct Edge {
        unsigned dest;
        unsigned capacity;
        unsigned duration;
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
    Graph();
    void addEdge(unsigned src, unsigned dest, unsigned capacity, unsigned duration);
    void dfs(int v);
    void bfs(int v);
    int bfs(int s, int t);
    };


#endif
