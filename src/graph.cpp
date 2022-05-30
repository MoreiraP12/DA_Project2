#include "graph.h"

Graph::Graph(unsigned num, bool dir) : n(num), hasDir(dir), nodes(num + 1) {
}

Graph::Graph() : nodes(0), hasDir(false) {}

void Graph::addEdge(unsigned src, unsigned dest, unsigned capacity, unsigned duration) {
    if (src < 1 || src > n || dest < 1 || dest > n) return;
    nodes[src].adj.push_back({dest, capacity, duration});
    if (!hasDir) nodes[dest].adj.push_back({src, capacity, duration});
}

void Graph::dfs(unsigned v) {
    nodes[v].visited = true;
    for (auto e: nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}

void Graph::bfs(unsigned v) {
    for (unsigned i = 1; i <= n; i++) {
        nodes[i].visited = false;
        nodes[i].parent = 0;
        nodes[i].lot = INF;

    }
    queue<unsigned > q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;

    while (!q.empty()) { // while there are still unvisited nodes
        unsigned u = q.front();
        q.pop();
        for (auto e: nodes[u].adj) {
            unsigned w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].parent = u;
                nodes[w].lot = min(nodes[u].lot, e.capacity);
            }
        }
    }
}

unsigned Graph::getNumNodes() {
    return n;
}

void Graph::maximumCapacityPath(unsigned src) {
    MaxHeap<unsigned, unsigned> heap(n, 0);
    for (unsigned v = 1; v <= n; v++) {
        nodes[v].parent = 0;
        nodes[v].lot = 0;
        nodes[v].visited = false;
        heap.insert(v, 0);
    }
    nodes[src].lot = INF;
    heap.increaseKey(src, nodes[src].lot);
    while (heap.getSize() != 0) {
        unsigned v = heap.removeMax();
        for (auto w: nodes[v].adj) {
            if (min(nodes[v].lot, w.capacity) > nodes[w.dest].lot) {
                nodes[w.dest].lot = min(nodes[v].lot, w.capacity);
                nodes[w.dest].parent = v;
                heap.increaseKey(w.dest, nodes[w.dest].lot);
            }
        }
    }
}

stack<unsigned> Graph::getPath(unsigned src, unsigned dest) {
    stack<unsigned> path;
    unsigned current = dest;
    while (current != src) {
        path.push(current);
        current = nodes[current].parent;
        if (current == 0) throw NoPathAvailable();
    }
    path.push(src);
    return path;
}

Graph::Node Graph::getNode(unsigned i) {
    return nodes[i];
}
/*
void Graph::ffbfs(int s, int t) {


    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (nodes[v].visited == false) {
                for(int i = 0; i < nodes[v].adj.size(); i++){
                    if(){

                    }
                    //visited[v] = true;
                }
            }
        }
    }
}

void Graph::maximumCapacity(unsigned groupSize, unsigned src, unsigned dest) {

    for (unsigned v = 1; v <= n; v++) {
        nodes[v].lot = 0;
        nodes[v].visited = false;
    }

    ffbfs(src, dest);


}*/

