#ifndef DA_PROJ2_DATA_H
#define DA_PROJ2_DATA_H

#include <string>
#include "graph.h"
using namespace std;

class Data {
public:
    Data();
    Graph loadGraph(unsigned numberFile);
};


#endif
