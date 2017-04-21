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





///**
// * searches for a given key, and if found returns the index the key is found at
// * @param key
// * @return index of found key
// */
//bool Configuration::search(std::string key) const {
//    for (int i = 0; i < myParamters.size(); ++i) {
//        if (myParamters[i].getKey() == key)
//            return true;
//    }
//    return false;
//}
//
//std::string Configuration::getValAsString(std::string name) {
//    int index = search(name);
//    std::string value = myParamters[index].getValue();
//    return value;
//}
//
//void Configuration::add(std::string key, std::string value) {
//    if (!search(key)) {
//        KeyValue<std::string, std::string> myVal(key, value);
//        myParamters.push_back(myVal);
//    }
//    else
//        throw std::invalid_argument("Cannot create duplicate Keys");
//}