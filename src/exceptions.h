//
// Created by daniel on 20-05-2022.
//

#ifndef DA_PROJ2_EXCEPTIONS_H
#define DA_PROJ2_EXCEPTIONS_H

#include <exception>
#include <string>

using namespace std;
/**
 * Unable to read file or any error related to the file
 */
class  ExceptionFile: public exception{
private:
    string filename;
public:
    explicit ExceptionFile(string filename);
    string what();
};
/**
 * No path is available from a certain source to a destination
 */
class NoPathAvailable: public exception{
public:
    NoPathAvailable()= default;
};


#endif
