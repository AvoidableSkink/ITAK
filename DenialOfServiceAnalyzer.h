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
    bool configured;
    int timeframe;
    int likelyThreshold;
    int possibleThreshold;
    ResultSet results;
public:
    DenialOfServiceAnalyzer();
    ResultSet run(std::istream& in);
    void setConfiguration(Configuration config);
    //functions to give test cases access to some data members
    int getTimeframe() { return timeframe; }
    int getLikelyThreshold() { return likelyThreshold; }
    int getPossibleThreshold() { return possibleThreshold; }
};


#endif //ITAK_DENIALOFSERVICEANALYZER_H
