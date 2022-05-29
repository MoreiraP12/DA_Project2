//
// Created by daniel on 20-05-2022.
//

#ifndef DA_PROJ2_EXCEPTIONS_H
#define DA_PROJ2_EXCEPTIONS_H

#include <exception>
#include <string>

using namespace std;

class  ExceptionFile: public exception{
private:
    string filename;
public:
    explicit ExceptionFile(string filename);
    string what();
};

class NoPathAvailable: public exception{
public:
    NoPathAvailable()= default;
};


#endif
