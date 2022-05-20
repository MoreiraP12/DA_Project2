#ifndef DA_FIRST_PROJECT_DATA_H
#define DA_FIRST_PROJECT_DATA_H
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include "../../DA_Project2/src/utils.h"

class Data {
private:
public:
    /**
     * Enables the data to be read to the vectors it receives from the file whose filenames are passed as arguments
     * @param packages pointer to the packages vector
     * @param packagesExpress pointer to the packages express vector
     * @param couriers pointer to the couriers vector
     * @param filenameVans name of the file that contains the vans
     * @param filenamePackages name of the file that contains the packages
     */
    Data();
    /**
     * Reads data from the filename passed in the constructor to populate the vector vans
     * It also creates couriers and attributes them an arbitrary van
     */
    /**
     * Reads data from the filename passed in the constructor to populate the vector package
     */
};


#endif //DA_FIRST_PROJECT_DATA_H
