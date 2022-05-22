//
// Created by daniel on 22-05-2022.
//

#include "manager.h"

Manager::Manager() {

}

void Manager::setGraph(Graph graph){
    routes = graph;
}

void Manager::displayGraph() {
    routes.bfs(1);
}
