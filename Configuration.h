//
// Created by klind on 4/18/2017.
//

#ifndef ITAK_CONFIGURATION_H
#define ITAK_CONFIGURATION_H

#include <vector>
#include "KeyValue.h"
#include "Dictionary.h"
#include <iostream>

class Configuration {
private:
    std::vector<KeyValue<std::string, std::string>> myParamters;
public:
    std::string getValAsString(std::string name);
    int getValAsInt(std::string name);
    double getValAsDouble(std::string name);
    int search(std::string key) const;
    void add(std::string key, std::string value);
};


#endif //ITAK_CONFIGURATION_H
