#include "menu.h"
using namespace std;

Manager Menu::manager = Manager();
Data Menu::data = Data();
int Menu::routesLoaded = -1;

Menu * Menu::invalidOption() {
    cout << "Invalid option" << std::endl;
    input::waitEnter();
    return this;
}

MainMenu::~MainMenu(){}

void MainMenu::show() {
    clearScreen();
    cout << "-| Main Menu |- " << endl;
    if(routesLoaded > 0)
        cout << "[File] " << routesLoaded << endl << endl;
    cout << "[1] Load Routes" << endl << endl;
    if(routesLoaded > 0){
        cout << "[2] Scenario 1.1" << endl;
        cout << "[3] Scenario 1.2" << endl;
        cout << "[4] Scenario 2.1" << endl;
        cout << "[5] Scenario 2.2" << endl;
        cout << "[6] Scenario 2.3" << endl;
        cout << "[7] Scenario 2.4" << endl;
        cout << "[8] Scenario 2.5" << endl;
    }
    cout << "[0] Exit" << endl;

}

Menu * MainMenu::getNextMenu() {
    int option;
    if(!input::get(option)){
        return invalidOption();
    }

    if(!routesLoaded){
        switch (option) {
            case 0:
                return nullptr;
            case 1:
                return new LoadRoutes();
            default: return nullptr;
        }
    }else{
        switch (option) {
            case 0:
                return nullptr;
            case 1: return new LoadRoutes();
            case 2: return new DisplayRoutes();
            default: return nullptr;
        }
    }
}

// ---------------  Load Routes ---------------
void LoadRoutes::show() {
    clearScreen();
    cout << "-| Load Routes |-" << endl;
    cout << "File Number? " << endl;
}

Menu *LoadRoutes::getNextMenu() {
    if(!input::get(routesLoaded)){
        return invalidOption();
    }
    try{
        Graph graph = data.loadGraph(routesLoaded);
        manager.setGraph(graph);
    }catch(ExceptionFile exception){
        routesLoaded = -1;
        cout << exception.what();
        input::waitEnter();
        return nullptr;
    }
    cout << "Successful loading!" << endl;
    input::waitEnter();
    return nullptr;
}

// ---------------  Display Routes ---------------
void DisplayRoutes::show() {
    clearScreen();
    cout << "-| Display Routes |-" << endl;
}

Menu *DisplayRoutes::getNextMenu() {
    manager.displayGraph();
    input::waitEnter();
    return nullptr;
}

