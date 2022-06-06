#ifndef DA_PROJ2_MANAGER_H
#define DA_PROJ2_MANAGER_H


#include "graph.h"
#include "maxHeap.h"
/**
 * "Backend" the project, everytime menu.h needs something it should call one "endpoint" - method of class Manager
 */
class Manager {
private:
    Graph routes;
public:
    Manager();
    /**
     * Set the graph that will be handled in all the methods
     * @param graph
     */
    void setGraph(Graph graph);
    /**
     * getter for the number of nodes in the attribute Graph routes
     * @return
     */
    unsigned getNumNodes();
    /**
     * Calls the required methods from graph.h and treats info to either be displayed to the user or to be used by yet another method from graph.h
     * @param src initial node
     * @param dest destination node
     */
    void scenario1_1(unsigned src, unsigned dest);
    /**
     * Calls the required methods from graph.h and treats info to either be displayed to the user or to be used by yet another method from graph.h
     * @param src initial node
     * @param dest destination node
     */
    void scenario1_2(unsigned src, unsigned dest);
    /**
     * Calls the required methods from graph.h and treats info to either be displayed to the user or to be used by yet another method from graph.h
     * @param src initial node
     * @param dest destination node
     * @param groupSize the size of the group that wants to go from src to dest
     */
    void scenario2_1(unsigned src, unsigned dest, unsigned groupSize);
    /**
     * Calls the required methods from graph.h and treats info to either be displayed to the user or to be used by yet another method from graph.h
     * @param path path that needs alteration in the form of a vector of int - that represent nodes in the graph
     * @param groupSize the current  size of the group that wants to go from src to dest
     * @param increment the amount of new members that want to do the journey
     */
    void scenario2_2(vector<unsigned> path, unsigned groupSize, unsigned increment);
    /**
      * Calls the required methods from graph.h and treats info to either be displayed to the user or to be used by yet another method from graph.h
      * @param src initial node
      * @param dest destination node
      */
    void scenario2_3(unsigned src, unsigned dest);
    /**
     * Calls the required methods from graph.h and treats info to either be displayed to the user or to be used by yet another method from graph.h
     */
    void scenario2_4();
    /**
    * Calls the required methods from graph.h and treats info to either be displayed to the user or to be used by yet another method from graph.h
    */
    void scenario2_5();
};


#endif
