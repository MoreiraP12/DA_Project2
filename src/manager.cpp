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

    try{
        Graph rGraph(routes.n);
        int i =  routes.edmondsKarp(rGraph, src, dest);
        if(i >= groupSize){
            cout << "Fantastic!!\nWe can fit your group in this path. " << endl;
        }
        else{
            cout << "Unfortunately your group is too big! " << endl;
        }

    }catch(NoPathAvailable& e){
        cout << "No path available between " << src << " and " << dest << endl;
        return;
    };
}

void Manager::scenario2_2(vector<unsigned> path, unsigned groupSize, unsigned increment) {
    try{
        Graph rGraph(routes.n);
        int i = routes.edmondsKarp(rGraph, path.front(), path.back(), path, groupSize);

        if(i < groupSize + increment){
            cout << "Unfortunately we cannot travel with more " << increment << " people." << endl;
        }
        else{
            cout << "We can take up to : " << i << " more people!\n" << endl;
        }

    }catch(NoPathAvailable& e){
        cout << "No path available between " << path.front() << " and " << path.back() << endl;
        return;
    }
}

void Manager::scenario2_3(unsigned src, unsigned dest) {
    stack<unsigned> path;
    try{
        Graph rGraph(routes.n);
        int i = routes.edmondsKarp(rGraph, src, dest);
        cout << "Max Group Size:" << i << endl;

    }catch(NoPathAvailable& e){
        cout << "No path available between " << src << " and " << dest << endl;
        return;
    }

}

void Manager::scenario2_4() {
    cout << "ES: " << routes.cpm() << endl;
}

void Manager::scenario2_5() {
    unsigned delay = routes.cpmDelay();
    stack<unsigned> stops = routes.getNodesDelay(delay);
    cout << "Delay: " << delay << endl;
    cout << "Stops: ";
    while (!stops.empty()){
        cout << stops.top() << " ";
        stops.pop();
    }
    cout << endl;
}


