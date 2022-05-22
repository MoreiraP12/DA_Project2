#include "menu.h"
using namespace std;

Manager Menu::manager = Manager();
Data Menu::data = Data();
bool Menu::routesLoaded = false;

Menu * Menu::invalidOption() {
    cout << "Invalid option" << std::endl;
    input::waitEnter();
    return this;
}

MainMenu::~MainMenu(){}

void MainMenu::show() {
    clearScreen();
    cout << "-| Main Menu |- " << endl;
    cout << "[1] Load Routes" << endl;
    if(routesLoaded) cout << "[2] Display Routes" << endl;
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
    unsigned numberFile;
    if(!input::get(numberFile)){
        return invalidOption();
    }
    try{
        Graph graph = data.loadGraph(numberFile);
        manager.setGraph(graph);
        routesLoaded = true;
    }catch(ExceptionFile exception){
        routesLoaded = false;
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
