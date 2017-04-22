//
// Created by klind on 4/18/2017.
//

#include "DenialOfServiceAnalyzer.h"

DenialOfServiceAnalyzer::DenialOfServiceAnalyzer() {
    configured = false;
}

ResultSet DenialOfServiceAnalyzer::run(std::istream& in) {
    //if the analyzer is not configured, return an empty ResultSet
    if (!configured)
    {
        ResultSet empty;
        return empty;
    }

//    std::string time, ip, src, des;
//    while (!in.eof())
//    {
//        in >> time >> ip >> src >> des;
//    }
}

void DenialOfServiceAnalyzer::setConfiguration(Configuration config) {
    configured = false;
    try {
        timeframe = config.getValAsInt("TimeFrame");
    }
    catch (std::out_of_range){
        std::cout << "TimeFrame required for DenialOfServiceAnalyzer. Configuration not set." << std::endl;
        return;
    }

    try {
        likelyThreshold = config.getValAsInt("Likely Attack Message Count");
    }
    catch (std::out_of_range){
        std::cout << "Likely Attack Message Count required for DenialOfServiceAnalyzer. Configuration not set." << std::endl;
        return;
    }

    try {
        possibleThreshold = config.getValAsInt("Possible Attack Message Count");
    }
    catch (std::out_of_range){
        std::cout << "Possible Attack Message Count required for DenialOfServiceAnalyzer. Configuration no set." << std::endl;
        return;
    }
    configured = true;
}