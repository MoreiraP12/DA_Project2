//
// Created by daniel on 22-05-2022.
//

#include "manager.h"

Manager::Manager() {

}

void Manager::setGraph(Graph graph){
    routes = graph;
}

void Manager::scenario1_1(int src, int dest) {
    stack<int> path;
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

int Manager::scenario1_2() {
    return 0;
}

int Manager::scenario2_1() {
    return 0;
}

int Manager::scenario2_2() {
    return 0;
}

int Manager::scenario2_3() {
    return 0;
}

int Manager::scenario2_4() {
    return 0;
}

int Manager::scenario2_5() {
    return 0;
}


