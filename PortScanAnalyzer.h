//
// Created by klind on 4/18/2017.
//

#ifndef ITAK_PORTSCANANALYZER_H
#define ITAK_PORTSCANANALYZER_H

#include "Analyzer.h"

class PortScanAnalyzer : public Analyzer{
private:
    Dictionary<std::string, std::vector<int>> myData;
    bool configured;
    int likelyThreshold;
    int possibleThreshold;
    ResultSet results;
public:
    PortScanAnalyzer();
    ResultSet run(std::istream&);
    void setConfiguration(Configuration config);
};


#endif //ITAK_PORTSCANANALYZER_H
