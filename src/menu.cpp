#include "../../DA_Project2/src/menu.h"

using namespace std;

Menu * Menu::invalidOption() {
    cout << "Invalid option" << std::endl;
    input::waitEnter();
    return this;
}

// --------------- Main Menu ---------------
Platform Menu::platform = Platform();
bool Menu::day = false;
bool Menu::scenario3 = false;


MainMenu::~MainMenu(){}

void MainMenu::show() {

    unsigned int options = 0;
    clearScreen();
    cout << "-| Main Menu |- ";
    if(day) cout << "Day";
    else cout << "Night";
    cout << endl << endl;

    cout << "Options: " << endl;
    if(!day) cout << "[" << ++options << "] " << "Start day\n";
    if(day) cout << "[" << ++options << "] " << "End day\n";
    if(!scenario3) cout << "[" << ++options << "] " << "Show All Packages\n";
    if(day && !scenario3) cout << "[" << ++options << "] " << "Show Packages In Distribution\n";
    if(!scenario3)cout << "[" << ++options << "] " << "Show Delayed Packages\n";
    if(!scenario3) cout << "[" << ++options << "] " << "Show Vans\n";
    if(!day) cout << "[" << ++options << "] " << "Show Express Packages\n";
    if(day && scenario3) cout << "[" << ++options << "] " << "Show Express Packages In Distribution\n";
    cout << "[0] Exit\n";
}

Menu * MainMenu::getNextMenu() {
    int option;
    if(!input::get(option)){
        return invalidOption();
    }
    if(day && !scenario3) {
        switch (option) {
            case 0:
                return nullptr;
            case 1:
                return new EndDay();
            case 2:
                return new ShowAllPackages();
            case 3:
                return new ShowPackagesInDistribution();
            case 4:
                return new ShowDelayedPackages();
            case 5:
                return new ShowVans();
            case 6:
                return new ShowPackagesExpress();
            default:
                return invalidOption();
        }
    }
    else if(day && scenario3){
        switch (option) {
            case 0:
                return nullptr;
            case 1:
                return new EndDay();
            case 2:
                return new ShowPackagesExpress();
            default:
                return invalidOption();
        }
    }
    else
    {
            switch (option) {
                case 0:
                    return nullptr;
                case 1:
                    return new StartDay();
                case 2:
                    return new ShowAllPackages();
                case 3:
                    return new ShowDelayedPackages();
                case 4:
                    return new ShowVans();
                case 5:
                    return new ShowPackagesExpress();
                default:
                    return invalidOption();
            }
        }
}

// --------------- StartDay  ---------------
void StartDay::show() {
    clearScreen();
    cout << "-| Scenarios |-" << endl << endl;
    cout << "Options: " << endl;
    unsigned int options = 0;
    cout << "[" << ++options << "] " << "Scenario 1\n";
    cout << "[" << ++options << "] " << "Scenario 2\n";
    cout << "[" << ++options << "] " << "Scenario 3\n";
    cout << "[0] Exit\n";
}
Menu * StartDay::getNextMenu() {
    int option;
    if(!input::get(option)){
        return invalidOption();
    }
    auto start = std::chrono::steady_clock::now();
    switch(option){
        case 0: return nullptr;
        case 1: platform.scenario1(); scenario3 = false; break;
        case 2: platform.scenario2(); scenario3 = false; break;
        case 3: platform.scenario3(); scenario3 = true; break;
        default: return invalidOption();
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    day = true;
    clearScreen();
    cout << "-| Scenario " << option << " |-" << endl;
    cout << "Processing completed!" << std::endl;
    std::cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    input::waitEnter();
    return nullptr ;
}

// ---------------  End Day ---------------
void EndDay::show() {
    cout << "-| End Day |-" << endl;
    clearScreen();
    cout << "Delivering the packages... " << endl;
    platform.deliveryPackages();
    day = false;
    scenario3 = false;
}
Menu * EndDay::getNextMenu() {
    input::waitEnter();
    return nullptr ;
}

// ---------------  Show Packages In Distribution ---------------
void ShowPackagesInDistribution::show() {
    clearScreen();
    cout << "-| Show Packages In Distribution |-" << endl << endl;

    platform.showPackagesInDistribution();
    cout << endl << endl << "Total Vans: " << platform.getNumVans() << " | Used Vans: " << platform.getNumUsedVans() << endl;
    cout << "Total Packages: " << platform.getNumPackages() << " | Packages in Distribution: " << platform.getNumPackagesInDistribution() << endl;
}
Menu * ShowPackagesInDistribution::getNextMenu() {
    input::waitEnter();
    return nullptr ;
}

// --------------- Show Delayed Packages  ---------------
void ShowDelayedPackages::show() {
    clearScreen();
    cout << "-| Show Delayed Packages |-" << endl << endl;
    platform.showDelayedPackages();
    cout << endl << endl << "Total Packages: " << platform.getNumPackages() << " | Packages Delayed: " << platform.getNumPackagesDelayed() << endl;
}
Menu * ShowDelayedPackages::getNextMenu() {
    input::waitEnter();
    return nullptr ;
}

// ---------------  Show All Packages ---------------
void ShowAllPackages::show() {
    clearScreen();
    cout << "-| Show All Packages |-" << endl << endl;
     platform.showAllPackages();
    cout << endl << endl << "Total Packages: " << platform.getNumPackages() << endl;
}
Menu * ShowAllPackages::getNextMenu() {
    input::waitEnter();
    return nullptr ;
}

// --------------- Show Vans  ---------------
void ShowVans::show() {
    clearScreen();
    cout << "-| Vans |-" << endl << endl;
    platform.showVans();

}
Menu * ShowVans::getNextMenu() {
    input::waitEnter();
    return nullptr ;
}

// --------------- Show Packages Express  ---------------

void ShowPackagesExpress::show() {
    clearScreen();
    cout << "-| Show Packages Express |-" << endl << endl;

    platform.showPackagesExpress();

}
Menu * ShowPackagesExpress::getNextMenu() {
    input::waitEnter();
    return nullptr ;
}