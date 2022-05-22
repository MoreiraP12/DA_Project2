#include "data.h"
#include "exceptions.h"
#include <fstream>
Data::Data(){

}

Graph Data::loadGraph(unsigned int numberFile) {
    string filename = "in";

    if(numberFile < 10)
        filename += to_string(0) + to_string(numberFile) + ".txt";
    else
        filename += to_string(numberFile) + ".txt";

    ifstream file;
    file.open(filename);
    if(file.fail()) throw ExceptionFile(filename);

    unsigned numNodes, numEdges;
    file >> numNodes >> numEdges;

    Graph graph(numNodes, true);
    unsigned counter = 0;
    unsigned src, dest, capacity, duration;
    while(counter < numEdges){
        file >> src >> dest >> capacity >> duration;
        graph.addEdge(src, dest, capacity, duration);
        counter++;
    }
    file.close();
    return graph;
}

