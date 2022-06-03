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
    void scenario1_1(unsigned src, unsigned dest);
    void scenario1_2(unsigned src, unsigned dest);
    void scenario2_1(unsigned src, unsigned dest, unsigned groupSize);
    void  scenario2_2(vector<unsigned> vect);
    void scenario2_3(unsigned src, unsigned dest);
    void scenario2_4(Graph graph);
    void scenario2_5(Graph graph);
};


#endif
