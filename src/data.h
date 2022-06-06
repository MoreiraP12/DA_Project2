#ifndef DA_PROJ2_DATA_H
#define DA_PROJ2_DATA_H

#include <string>
#include "graph.h"
using namespace std;

class Data {
public:
    Data();
    /**
     * Loads the data from a file to a graph
     * @param numberFile
     * @return
     */
    Graph loadGraph(int numberFile);
};


#endif
