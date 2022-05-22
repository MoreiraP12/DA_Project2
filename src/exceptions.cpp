//
// Created by daniel on 20-05-2022.
//

#include "exceptions.h"

using namespace std;

ExceptionFile::ExceptionFile(string filename):filename(filename) {
}

string ExceptionFile::what() {
    return "Error opening the file: " + filename + "\n";
}
