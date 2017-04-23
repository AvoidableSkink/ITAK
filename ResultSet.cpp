//
// Created by klind on 4/18/2017.
//

#include "ResultSet.h"

void ResultSet::addResult(std::string key, std::vector<std::string> value) {
    myResults.add(key, value);
}

void ResultSet::print() {
    for (int i = 0; i < myResults.getCount(); ++i) {
        std::cout << myResults.getByIndex(i).getKey() << ": " << std::endl;

        std::vector<std::string> value;
        value = myResults.getByIndex(i).getValue();
        for (int j = 0; j < value.size(); ++j) {
            std::cout << "  " << value[i] << std::endl;
        }
    }
}