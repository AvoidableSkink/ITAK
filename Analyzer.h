//
// Created by klind on 4/18/2017.
//

#ifndef ITAK_ANALYZER_H
#define ITAK_ANALYZER_H

#include <iostream>
#include "ResultSet.h"
#include "Configuration.h"


class Analyzer {
protected:
    bool configured;
    int likelyThreshold;
    int possibleThreshold;
    ResultSet results;
public:
    virtual ResultSet run(std::istream&){};
    virtual void setConfiguration(Configuration config){};
    virtual void fill(std::string, std::string){};

    int getLikelyThreshold() { return likelyThreshold; }
    int getPossibleThreshold() { return possibleThreshold; }
};


#endif //ITAK_ANALYZER_H
