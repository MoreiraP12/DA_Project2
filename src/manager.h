#ifndef DA_PROJ2_MANAGER_H
#define DA_PROJ2_MANAGER_H


#include "graph.h"
#include "maxHeap.h"

class Manager {
private:
    Graph routes;
public:
    Manager();
    void setGraph(Graph graph);
    unsigned getNumNodes();
    void scenario1_1(int src, int dest);
    int scenario1_2();
    int scenario2_1();
    int scenario2_2();
    int scenario2_3();
    int scenario2_4();
    int scenario2_5();
};


#endif
