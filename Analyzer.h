//
// Created by klind on 4/18/2017.
//

#ifndef ITAK_ANALYZER_H
#define ITAK_ANALYZER_H

#include <iostream>
#include "ResultSet.h"
#include "Configuration.h"


class Analyzer {
public:
    virtual ResultSet run(std::istream&);
    virtual void setConfiguration(Configuration config);
};


#endif //ITAK_ANALYZER_H
