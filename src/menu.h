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

/**
 * Menu encharged of loading the files to a usable data structure
 */
class LoadRoutes : public Menu {
public:
    explicit LoadRoutes():Menu(){};
    void show() override;
    Menu * getNextMenu() override;
};

/**
 * Menu relevant to the exercise 1.1 where the need functions from manager.h are called and the needed arguments are fetched from the user
 */
class Scenario1_1 : public Menu {
public:
    explicit Scenario1_1():Menu(){};
    void show() override;
    Menu * getNextMenu() override;
};

/**
 * Menu relevant to the exercise 1.2 where the need functions from manager.h are called and the needed arguments are fetched from the user
 */
class Scenario1_2 : public Menu {
public:
    explicit Scenario1_2():Menu(){};
    void show() override;
    Menu * getNextMenu() override;
};

/**
 * Menu relevant to the exercise 2.1 where the need functions from manager.h are called and the needed arguments are fetched from the user
 */
class Scenario2_1 : public Menu {
public:
    explicit Scenario2_1():Menu(){};
    void show() override;
    Menu * getNextMenu() override;
};
/**
 * Menu relevant to the exercise 2.2 where the need functions from manager.h are called and the needed arguments are fetched from the user
 */
class Scenario2_2 : public Menu {
public:
    explicit Scenario2_2():Menu(){};
    void show() override;
    Menu * getNextMenu() override;
};

/**
 * Menu relevant to the exercise 2.3 where the need functions from manager.h are called and the needed arguments are fetched from the user
 */
class Scenario2_3 : public Menu {
public:
    explicit Scenario2_3():Menu(){};
    void show() override;
    Menu * getNextMenu() override;
};

/**
 * Menu relevant to the exercise 2.4 where the need functions from manager.h are called and the needed arguments are fetched from the user
 */
class Scenario2_4 : public Menu {
public:
    explicit Scenario2_4():Menu(){};
    void show() override;
    Menu * getNextMenu() override;
};

/**
 * Menu relevant to the exercise 2.5 where the need functions from manager.h are called and the needed arguments are fetched from the user
 */
class Scenario2_5 : public Menu {
public:
    explicit Scenario2_5():Menu(){};
    void show() override;
    Menu * getNextMenu() override;
};

