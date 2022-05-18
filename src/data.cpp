#include "../../DA_Project2/src/data.h"

#include <utility>

Data::Data(std::vector<Package>* packages,std::vector<PackageExpress>* packagesExpress, std::vector<Courier>* couriers,  std::string filenameVans, std::string filenamePackages){
    this->packages = packages;
    this->packagesExpress = packagesExpress;
    this->couriers = couriers;
    this->filenameVans = std::move(filenameVans);
    this->filenamePackages = std::move(filenamePackages);

}

void Data::readVansTxt(){
    std::cout << this->filenameVans << std::endl;
    std::ifstream infile("../dataset/" + this->filenameVans);
    if(!infile.is_open()){
        throw ErrorOpeningInfile((std::string &) this->filenameVans);
    }
    std::string line;
    std::getline(infile, line);
    int i = 1;
    while(std::getline(infile, line)){
        std::stringstream ss(line);
        int volMax, weightMax, cost;
        ss >> volMax >> weightMax >> cost;
        Van newVan(volMax, weightMax, i);
        Courier newCourier(newVan, cost);
        couriers->push_back(newCourier);
        i++;
    }
    infile.close();
}

void Data::readPackagesTxt(){
    int i = 1;
    int vol, weight, reward, duration;
    char check;
    std::ifstream infile("../dataset/" + this->filenamePackages);
    if(!infile.is_open()){
        throw ErrorOpeningInfile((std::string &) this->filenamePackages);
    }
    std::string line;
    std::getline(infile, line);
    while(std::getline(infile, line)){
        std::stringstream ss(line);
        ss >> check;
        switch (check) {
            case 's':
                ss >> vol >> weight >> reward >> duration;
                packagesExpress->push_back( PackageExpress(i, vol,weight,reward,duration));
                break;
            case 'n':
                ss >> vol >> weight >> reward;
                packages->push_back( Package(i, vol,weight,reward));
                break;
            default:
                std::cout << "Error! Express (s or n)" << std::endl;
        }
        i++;
    }
    infile.close();
}
