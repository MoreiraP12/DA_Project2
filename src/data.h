#ifndef DA_FIRST_PROJECT_DATA_H
#define DA_FIRST_PROJECT_DATA_H
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include "package.h"
#include "courier.h"
#include "van.h"
#include "exceptions.h"
#include "../../DA_Project2/src/utils.h"

class Data {
private:
    std::vector<Package>* packages;
    std::vector<PackageExpress>* packagesExpress;
    std::vector<Courier>* couriers;
    std::string filenameVans;
    std::string filenamePackages;
public:
    /**
     * Enables the data to be read to the vectors it receives from the file whose filenames are passed as arguments
     * @param packages pointer to the packages vector
     * @param packagesExpress pointer to the packages express vector
     * @param couriers pointer to the couriers vector
     * @param filenameVans name of the file that contains the vans
     * @param filenamePackages name of the file that contains the packages
     */
    Data(std::vector<Package>* packages, std::vector<PackageExpress>* packagesExpress, std::vector<Courier>* couriers,  std::string filenameVans, std::string filenamePackages);
    /**
     * Reads data from the filename passed in the constructor to populate the vector vans
     * It also creates couriers and attributes them an arbitrary van
     */
    void readVansTxt();
    /**
     * Reads data from the filename passed in the constructor to populate the vector package
     */
    void readPackagesTxt();
};


#endif //DA_FIRST_PROJECT_DATA_H
