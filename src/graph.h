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
    /**
     * Add a new edge to the graph
     * @param src the source of the new edge
     * @param dest the dest of the new edge
     * @param capacity the capacity of the new edge
     * @param duration the duration of the new edge
     */
    void addEdge(unsigned src, unsigned dest, unsigned capacity, unsigned duration);
    /**
     * Default Depth First Search
     * @param v
     */
    void dfs(unsigned v);
    /**
     * Default Breadth First Search
     * @param v
     */
    void bfs(unsigned v);
    /**
     * Getter for a node in the position i in the nodes vector in the graph
     * @param i
     * @return
     */
    Node getNode(unsigned i);
    /**
     * Maximum capacity of a single path
     * @param src
     */
    void maximumCapacityPath(unsigned src);
    /**
     * Number of nodes of the graph
     * @return
     */
    unsigned getNumNodes();
    /**
     * Prints the path from src to dest
     * @param src
     * @param dest
     * @return
     */
    stack<unsigned> getPath(unsigned src, unsigned dest);
    unsigned cpm();
    unsigned cpmDelay();
    stack<unsigned> getNodesDelay(unsigned delay);
    int fordFulkerson(Graph &rGraph, int s, int t, vector<unsigned> path=vector<unsigned>(), int groupSize = 0);
    /**
     * Modified breadth first search for the fordFulkerson
     * @param rGraph
     * @param s
     * @param t
     * @return
     */
    bool auxbfs(Graph &rGraph, int s, int t);
};


#endif
