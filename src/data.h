#ifndef DA_FIRST_PROJECT_DATA_H
#define DA_FIRST_PROJECT_DATA_H

#include <string>
#include "graph.h"
using namespace std;

class Data {
public:
    Data();
    Graph loadGraph(unsigned numberFile);
};


#endif //DA_FIRST_PROJECT_DATA_H
