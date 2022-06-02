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
            case 2: return new Scenario1_1();
            case 3: return new Scenario1_2();
            case 4: return new Scenario2_1();
            case 5: return new Scenario2_2();
            case 6: return new Scenario2_3();
            case 7: return new Scenario2_4();
            case 8: return new Scenario2_5();
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

// ---------------  Scenario 1.1 ---------------

void Scenario1_1::show() {
    clearScreen();
    cout << "-| Scenario 1.1 |-" << endl;
    cout << "[File] " << routesLoaded << endl << endl;
}

Menu *Scenario1_1::getNextMenu() {
    unsigned origin, destination;
    cout << "Origin? " << endl;
    if(!input::get(origin)){
        return invalidOption();
    }
    if(!(origin >= 1 && origin <=    manager.getNumNodes())){
        return invalidOption();
    }
    cout << endl << "Destination? " << endl;
    if(!input::get(destination)){
        return invalidOption();
    }
    if(!(destination >= 1 && destination <= manager.getNumNodes()) || destination == origin){
        return invalidOption();
    }

    manager.scenario1_1(origin, destination);
    input::waitEnter();
    return nullptr;
}

// ---------------  Scenario 1.2 ---------------

void Scenario1_2::show() {
    clearScreen();
    cout << "-| Scenario 1.2 |-" << endl;
    cout << "[File] " << routesLoaded << endl << endl;
}

Menu *Scenario1_2::getNextMenu() {
    unsigned origin, destination;
    cout << "Origin? " << endl;
    if(!input::get(origin)){
        return invalidOption();
    }
    if(!(origin >= 1 && origin <= manager.getNumNodes())){
        return invalidOption();
    }
    cout << endl << "Destination? " << endl;
    if(!input::get(destination)){
        return invalidOption();
    }
    if(!(destination >= 1 && destination <= manager.getNumNodes()) || destination == origin){
        return invalidOption();
    }

    manager.scenario1_2(origin, destination);
    input::waitEnter();
    return nullptr;
}


// ---------------  Scenario 2.1 ---------------

void Scenario2_1::show() {
    clearScreen();
    cout << "-| Scenario 2.1 |-" << endl;
    cout << "[File] " << routesLoaded << endl << endl;
}

Menu *Scenario2_1::getNextMenu() {
    unsigned origin, destination,groupSize;
    cout << "Origin? " << endl;
    if(!input::get(origin)){
        return invalidOption();
    }
    if(!(origin >= 1 && origin <= manager.getNumNodes())){
        return invalidOption();
    }
    cout << endl << "Destination? " << endl;
    if(!input::get(destination)){
        return invalidOption();
    }
    if(!(destination >= 1 && destination <= manager.getNumNodes()) || destination == origin){
        return invalidOption();
    }
    cout << endl << "Group Size? " << endl;
    if(!input::get(groupSize)){
        return invalidOption();
    }
    if(groupSize < 1){
        return invalidOption();
    }

    manager.scenario2_1(origin, destination, groupSize);

    input::waitEnter();
    return nullptr;
}


// ---------------  Scenario 2.2 ---------------

void Scenario2_2::show() {

}

Menu *Scenario2_2::getNextMenu() {
    return nullptr;
}


// ---------------  Scenario 2.3 ---------------

void Scenario2_3::show() {
    clearScreen();
    cout << "-| Scenario 2.3 |-" << endl;
    cout << "[File] " << routesLoaded << endl << endl;
}

Menu *Scenario2_3::getNextMenu() {
    unsigned origin, destination;
    cout << "Origin? " << endl;
    if(!input::get(origin)){
        return invalidOption();
    }
    if(!(origin >= 1 && origin <= manager.getNumNodes())){
        return invalidOption();
    }
    cout << endl << "Destination? " << endl;
    if(!input::get(destination)){
        return invalidOption();
    }
    if(!(destination >= 1 && destination <= manager.getNumNodes()) || destination == origin){
        return invalidOption();
    }

    manager.scenario2_3(origin, destination);

    input::waitEnter();
    return nullptr;
}


// ---------------  Scenario 2.4 ---------------

void Scenario2_4::show() {
    clearScreen();
    cout << "-| Scenario 2.4 |-" << endl;
    cout << "[File] " << routesLoaded << endl << endl;
}

Menu *Scenario2_4::getNextMenu() {
    unsigned origin, destination;
    cout << "Origin? " << endl;
    if(!input::get(origin)){
        return invalidOption();
    }
    if(!(origin >= 1 && origin <= manager.getNumNodes())){
        return invalidOption();
    }
    cout << endl << "Destination? " << endl;
    if(!input::get(destination)){
        return invalidOption();
    }
    if(!(destination >= 1 && destination <= manager.getNumNodes()) || destination == origin){
        return invalidOption();
    }

    Graph tempGraph = data.loadGraph(12);

    manager.scenario2_4(tempGraph);
    input::waitEnter();
    return nullptr;
}


// ---------------  Scenario 2.5 ---------------

void Scenario2_5::show() {
    clearScreen();
    cout << "-| Scenario 2.4 |-" << endl;
    cout << "[File] " << routesLoaded << endl << endl;
}

Menu *Scenario2_5::getNextMenu() {
    unsigned origin, destination;
    cout << "Origin? " << endl;
    if(!input::get(origin)){
        return invalidOption();
    }
    if(!(origin >= 1 && origin <= manager.getNumNodes())){
        return invalidOption();
    }
    cout << endl << "Destination? " << endl;
    if(!input::get(destination)){
        return invalidOption();
    }
    if(!(destination >= 1 && destination <= manager.getNumNodes()) || destination == origin){
        return invalidOption();
    }

    Graph tempGraph = data.loadGraph(12);

    manager.scenario2_5(tempGraph);
    input::waitEnter();
    return nullptr;
}
