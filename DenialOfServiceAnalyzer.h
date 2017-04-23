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
    int timeframe;

public:
    DenialOfServiceAnalyzer();
    ResultSet run(std::istream& in);
    void setConfiguration(Configuration config);
    void fill(std::string ip, std::string time);
    //functions to give test cases access to some data members
    int getTimeframe() { return timeframe; }
};


#endif //ITAK_DENIALOFSERVICEANALYZER_H
