//
// Created by daniel on 22-05-2022.
//

#include "manager.h"

Manager::Manager() {

}

void Manager::setGraph(Graph graph){
    routes = graph;
}

void Manager::scenario1_1(unsigned src, unsigned dest) {
    stack<unsigned> path;
    try{
        routes.maximumCapacityPath(src);
        path = routes.getPath(src, dest);
    }catch(NoPathAvailable& e){
        cout << "No path available between " << src << " and " << dest << endl;
        return;
    }
    cout << "Maximum Capacity: " << routes.getNode(dest).lot << endl;
    cout << "Path: ";
    while (!path.empty()){
        cout << path.top() << "  ";
        path.pop();
    }
    cout << endl;
}

unsigned Manager::getNumNodes() {
    return routes.getNumNodes();
}

void Manager::scenario1_2(unsigned src, unsigned dest) {
    stack<unsigned> path;
    try{
        routes.maximumCapacityPath(src);
        path = routes.getPath(src, dest);
    }catch(NoPathAvailable& e){
        cout << "No path available between " << src << " and " << dest << endl;
        return;
    }
    cout << "-| Maximum capacity |-" << endl;
    cout << "Maximum Capacity: " << routes.getNode(dest).lot << endl;
    cout << "Number of passenger transfers: " << path.size() - 2 << endl;
    cout << "Path: ";
    while (!path.empty()){
        cout << path.top() << "  ";
        path.pop();
    }
    cout << endl;

    try{
        routes.bfs(src);
        path = routes.getPath(src, dest);
    }catch (NoPathAvailable& e){
        cout << "No path available between " << src << " and " << dest << endl;
        return;
    }
    cout << endl;
    cout << "-| Lower number of passenger transfers |-" << endl;
    cout << "Maximum Capacity: " << routes.getNode(dest).lot << endl;
    cout << "Number of passenger transfers: " << path.size() - 2 << endl;
    cout << "Path: ";
    while (!path.empty()){
        cout << path.top() << "  ";
        path.pop();
    }
    cout << endl;
}

void Manager::scenario2_1(unsigned src, unsigned dest, unsigned groupSize) {
    stack<unsigned> path;
    try{
        Graph rGraph(routes.n);
        int i = routes.fordFulkerson(rGraph, src, dest);
        if(i < groupSize){
            cout << "\nUnfortunately, we weren't able to accomodate your group!\nTry again with a group of less than " << i << " people and follow the path above. \n" << endl;
        }
        else{
            cout << "\nWe can accomodate your group !!" << endl;
        }
    }catch(NoPathAvailable& e){
        cout << "No path available between " << src << " and " << dest << endl;
        return;
    }
}

int Manager::scenario2_2() {
    return 0;
}

void Manager::scenario2_3(unsigned src, unsigned dest) {
    stack<unsigned> path;
    try{
        Graph rGraph(routes.n);
        cout << "Max Group Size:" << routes.fordFulkerson(rGraph, src, dest) << endl;
        path = rGraph.getPath(src, dest);
        while (!path.empty()){
            cout << path.top() << "  ";
            path.pop();
        }
    }catch(NoPathAvailable& e){
        cout << "No path available between " << src << " and " << dest << endl;
        return;
    }

}

void Manager::scenario2_4(Graph graph) {
    cout << "ES: " << graph.cpm() << endl;
}

void Manager::scenario2_5(Graph graph) {
    unsigned delay = graph.cpmDelay();
    stack<unsigned> stops = graph.getNodesDelay(delay);
    cout << "Delay: " << delay << endl;
    cout << "Stops: ";
    while (!stops.empty()){
        cout << stops.top() << " ";
        stops.pop();
    }
    cout << endl;
}


