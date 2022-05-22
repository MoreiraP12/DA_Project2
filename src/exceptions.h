//
// Created by daniel on 20-05-2022.
//

#ifndef DA_FIRST_PROJECT_EXCEPTIONS_H
#define DA_FIRST_PROJECT_EXCEPTIONS_H

#include <exception>
#include <string>

using namespace std;

class  ExceptionFile: public exception{
private:
    string filename;
public:
    ExceptionFile(string filename);
    string what();
};


#endif //DA_FIRST_PROJECT_EXCEPTIONS_H
