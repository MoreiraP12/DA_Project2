#ifndef DA_PROJ2_MANAGER_H
#define DA_PROJ2_MANAGER_H


#include "graph.h"

class Manager {
private:
    Graph routes;
public:
    Manager();
    void setGraph(Graph graph);
    void displayGraph();
};


#endif
