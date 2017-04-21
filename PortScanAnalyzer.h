//
// Created by klind on 4/18/2017.
//

#ifndef ITAK_PORTSCANANALYZER_H
#define ITAK_PORTSCANANALYZER_H

#include "Analyzer.h"

class PortScanAnalyzer : public Analyzer{
public:
    ResultSet run(std::istream&);
    void setConfiguration(Configuration);
};


#endif //ITAK_PORTSCANANALYZER_H
