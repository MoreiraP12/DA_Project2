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

int Graph::ekbfs(int s, int t)//breadth first search
{

    queue<int> q;
    nodes[s].parent = -2;
    q.push(s);
    //path_flow[s] = INF;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto i: nodes[u].adj) {
            int v = i.dest;
            if(nodes[v].parent == 0)
            {
                if(i.capacity - i.flow > 0)
                {
                    nodes[v].visited = true;
                    // update parent node
                    nodes[v].parent = u;
                    // check min residual edge capacity
                    unsigned u_flow;
                    if(u == s){
                        i.flow = i.capacity - i.flow;
                    }
                    else{
                        for(auto k: nodes[u].adj){
                            if(k.dest == v){
                                u_flow = k.flow;
                                break;
                            }
                        }
                        i.flow = min(u_flow,i.capacity - i.flow);
                    }

                    // if bfs reach end node, then terminate
                    if(v == t) return i.flow;

                    // add future node to queue
                    q.push(v);
                }
            }
        }
    }
    return 0;
}
int Graph::edmondsKarp(int source, int sink)
{
    for (unsigned v = 1; v <= n; v++) {
        nodes[v].parent = 0;
        nodes[v].lot = 0;
        nodes[v].visited = false;
        for(auto i: nodes[v].adj){
            i.flow = 0;
        }
    }
    int maxFlow = 0;
    while(1) {
        //ind an augmented path and max flow corresponding to it
        int flow = ekbfs(source, sink);
        // if no path available, flow will be 0
        if(flow==0)
            break;
        maxFlow += flow;
        // we update the passed flow matrix
        for (unsigned v = 1; v <= n; v++) {
            nodes[v].parent = 0;
            nodes[v].lot = 0;
            if(nodes[v].visited) {
                for (auto i: nodes[v].adj) {
                    if (nodes[i.dest].visited) {
                        i.flow = flow;
                    }
                }
            }
        }
    }
    return maxFlow;
}

