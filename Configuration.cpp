//
// Created by klind on 4/18/2017.
//

#include "Configuration.h"
#include "Utils.h"

void Configuration::addParamter(std::string name, std::string value) {
    myParamters.add(name, value);
}

std::string Configuration::getValAsString(std::string name) {
    KeyValue<std::string, std::string> myKeyVal = myParamters.getByKey(name);
    return myKeyVal.getValue();
}

int Configuration::getValAsInt(std::string name) {
    KeyValue<std::string, std::string> myKeyVal = myParamters.getByKey(name);
    int value = convertStringToInt(myKeyVal.getValue(), nullptr);
    return value;
}

double Configuration::getValAsDouble(std::string name) {
    KeyValue<std::string, std::string> myKeyVal = myParamters.getByKey(name);
    double value = convertStringToDouble(myKeyVal.getValue(), nullptr);
    return value;
}





