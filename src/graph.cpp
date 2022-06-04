#include "graph.h"

Graph::Graph(unsigned num, bool dir) : n(num), hasDir(dir), nodes(num + 1) {
}

Graph::Graph() : nodes(0), hasDir(false) {}

void Graph::addEdge(unsigned src, unsigned dest, unsigned capacity, unsigned duration) {
    if (src < 1 || src > n || dest < 1 || dest > n) return;
    nodes[src].adj.push_back({dest, capacity, duration});
    //if (!hasDir) nodes[dest].adj.push_back({src, capacity, duration});

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

bool Graph::ekbfs(Graph &rGraph, int s, int t)
{
    for(auto x: rGraph.nodes){
        x.visited = false;
    }
    queue<int> q;
    q.push(s);
    rGraph.nodes[s].visited = true;
    rGraph.nodes[s].parent = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for(Edge& edge: rGraph.nodes[u].adj){
            if (rGraph.nodes[edge.dest].visited == false && edge.capacity > 0) {
                q.push(edge.dest);
                rGraph.nodes[edge.dest].parent = u;
                rGraph.nodes[edge.dest].visited = true;
            }
            if(edge.dest == t){
                return true;
            }
        }
    }

    return false;
}

int Graph::edmondsKarp(Graph& rGraph, int s, int t, vector<unsigned> path, int groupSize)
{
    int u, v;
    for (u = 1; u <= n; u++){
        for(auto x: nodes[u].adj){
            rGraph.addEdge(u, x.dest, x.capacity, x.duration);
        }
    }

    for(int i = 0; i < path.size(); i++){
        for(auto edge: rGraph.nodes[path[i]].adj){
            if(edge.dest == path[i+1]){
                edge.capacity -= groupSize;
            }
        }
    }

    for (u = 1; u <= n; u++){
        rGraph.nodes[u].visited = false;
        rGraph.nodes[u].parent = 0;
    }

    int max_flow = 0;

    // Updating the residual values of edges
    while (ekbfs(rGraph, s, t)) {
        unsigned path_flow = INT_MAX;
        for (v = t; v != s; v = rGraph.nodes[v].parent) {
            u = rGraph.nodes[v].parent;
            for(Edge &x: rGraph.nodes[u].adj){
                if(x.dest == v){
                    path_flow = min(path_flow, x.capacity);
                }
            }
        }

        if(path_flow == 0){
            return max_flow;
        }
        for (v = t; v != s; v = rGraph.nodes[v].parent) {
            u = rGraph.nodes[v].parent;
            for(Edge& x: rGraph.nodes[u].adj){
                if(x.dest == v){
                    x.capacity -= path_flow;
                }
            }
            for(Edge& j: rGraph.nodes[v].adj){
                if(j.dest == u){
                    j.capacity += path_flow;
                }
                else{
                    rGraph.addEdge(v, u, path_flow, 0);
                }
            }

        }

        // Adding the path flows
        max_flow += path_flow;
        for (u = 1; u <= n; u++){
            rGraph.nodes[u].visited=false;
        }
        stack<unsigned> path;
        path = rGraph.getPath(s, t);
        while (!path.empty()){
            cout << path.top() << "  ";
            path.pop();
        }
        cout << endl;
    }

    return max_flow;
}

unsigned Graph::cpm() {
    for(int v = 1; v <= n; v++){
        nodes[v].latestArr = 0;
        nodes[v].parent = 0;
        nodes[v].degree = 0;
    }

    for(int v = 1; v <= n; v++){
        for(auto e: nodes[v].adj){
            nodes[e.dest].degree++;
        }
    }

    stack<unsigned> s;
    for(unsigned v = 1; v<=n;v++)
        if(nodes[v].degree == 0) s.push(v);

    unsigned durMin = 0;

    while(!s.empty()){
        unsigned v = s.top(); s.pop();
        if( durMin < (int) nodes[v].latestArr){
            durMin = nodes[v].latestArr;
        }
        for(auto w: nodes[v].adj){
            if(nodes[w.dest].latestArr < nodes[v].latestArr + w.duration){
                nodes[w.dest].latestArr = nodes[v].latestArr + w.duration;
                nodes[w.dest].parent = v;
            }
            nodes[w.dest].degree--;
            if(nodes[w.dest].degree == 0)
                s.push(w.dest);
        }
    }
    return durMin;
}

unsigned Graph::cpmDelay() {
    for(int v = 1; v <= n; v++){
        nodes[v].latestArr = 0;
        nodes[v].parent = 0;
        nodes[v].degree = 0;
        nodes[v].earliestArr = 0;
    }

    for(int v = 1; v <= n; v++){
        for(auto e: nodes[v].adj){
            nodes[e.dest].degree++;
        }
    }

    stack<unsigned> s;
    for(unsigned v = 1; v<=n;v++)
        if(nodes[v].degree == 0) s.push(v);

    unsigned delay = 0;

    while(!s.empty()){
        unsigned v = s.top(); s.pop();
        delay = max(delay, nodes[v].latestArr - nodes[v].earliestArr);
        for(auto w: nodes[v].adj){
            if(nodes[w.dest].latestArr < nodes[v].latestArr + w.duration){
                nodes[w.dest].latestArr = nodes[v].latestArr + w.duration;
                nodes[w.dest].parent = v;
            }
            if(nodes[w.dest].earliestArr == 0)
                nodes[w.dest].earliestArr = nodes[v].latestArr + w.duration;
            else
                nodes[w.dest].earliestArr = min(nodes[w.dest].earliestArr, nodes[v].latestArr + w.duration);

            nodes[w.dest].degree--;
            if(nodes[w.dest].degree == 0)
                s.push(w.dest);
        }

    }
    return delay;
}

stack<unsigned> Graph::getNodesDelay(unsigned delay) {
    stack<unsigned> result;
    for(int i = 1; i <= n; i++){
        if(nodes[i].latestArr - nodes[i].earliestArr == delay)
            result.push(i);
    }
    return result;
}

