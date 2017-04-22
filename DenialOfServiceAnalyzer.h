//
// Created by klind on 4/18/2017.
//

#ifndef ITAK_DENIALOFSERVICEANALYZER_H
#define ITAK_DENIALOFSERVICEANALYZER_H

#include "Analyzer.h"
#include "Dictionary.h"

class DenialOfServiceAnalyzer : public Analyzer{
private:
    Dictionary<std::string, Dictionary<int, int>> myData;
    bool configured = false;
    int timeframe = NULL;
    int likelyThreshold = NULL;
    int possibleThreshold = NULL;
public:
    ResultSet run(std::istream&);
    void setConfiguration(Configuration config);
};


#endif //ITAK_DENIALOFSERVICEANALYZER_H
