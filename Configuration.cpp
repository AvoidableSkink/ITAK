////
//// Created by klind on 4/18/2017.
////
//
//#include "Configuration.h"
//
///**
// * searches for a given key, and if found returns the index the key is found at
// * @param key
// * @return index of found key
// */
//int Configuration::search(std::string key) const {
//    for (int i = 0; i < myParamters.size(); ++i) {
//        if (myParamters[i].getKey() == key)
//            return i;
//    }
//    return 0;
//}
//
//std::string Configuration::getValAsString(std::string name) {
//    int index = search(name);
//    std::string value = myParamters[index].getValue();
//    return value;
//}
//
//void Configuration::add(std::string key, std::string value) {
//    if (search(key) != 0) {
//        KeyValue<std::string, std::string> myVal(key, value);
//        myParamters.push_back(myVal);
//    }
//    else
//        throw std::invalid_argument("Cannot create duplicate Keys");
//}