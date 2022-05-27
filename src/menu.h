#include <iostream>
#include <vector>
#include "graph.h"
#include "input.h"
#include "utils.h"
#include "manager.h"
#include "data.h"
#include "exceptions.h"
#include <chrono>

using namespace std;
/**
 * a Menu that bases its implementation on a stack
 *
 * Every menu has two methods:
 * show() - responsible for the "view" in the console, provides useful messages to the user or important info in text form
 * getNextMenu() - responsible for the behaviour aspect of the program, receives inputs and returns the new path in form of a pointer
 */
class Menu{

protected:
    static Manager manager;
    static Data data;
    static int routesLoaded;
    Menu * invalidOption();
public:
    explicit Menu(){};
    virtual ~Menu() = default;
    /**
     * Show information associated with the menu
     */
    virtual void show() = 0;
    /**
     * Return a pointer to the next menu ('nullptr' and 'this' can also be returned)
     * nullptr -> Return to previous menu
     * this -> Don't change the menu
     * @return Menu * to next menu
     */
    virtual Menu * getNextMenu() = 0;
};

/**
 * Displays all possible listings
 */
class MainMenu : public Menu {
public:
    explicit MainMenu():Menu(){};
    ~MainMenu() override;
    void show() override;
    Menu * getNextMenu() override;
};

class LoadRoutes : public Menu {
public:
    explicit LoadRoutes():Menu(){};
    void show() override;
    Menu * getNextMenu() override;
};

class DisplayRoutes : public Menu {
public:
    explicit DisplayRoutes():Menu(){};
    void show() override;
    Menu * getNextMenu() override;
};
