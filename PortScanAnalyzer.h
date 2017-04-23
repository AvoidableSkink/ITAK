//
// Created by klind on 4/18/2017.
//

#ifndef ITAK_PORTSCANANALYZER_H
#define ITAK_PORTSCANANALYZER_H

#include "Analyzer.h"

class PortScanAnalyzer : public Analyzer{
private:
    Dictionary<std::string, std::vector<int>> myData;

public:
    PortScanAnalyzer();
    ResultSet run(std::istream&);
    void setConfiguration(Configuration config);
    void fill(std::string ip, std::string des);
};


#endif //ITAK_PORTSCANANALYZER_H
