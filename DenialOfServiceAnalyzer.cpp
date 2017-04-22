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
    timeframe = config.getValAsInt("TimeFrame");
    likelyThreshold = config.getValAsInt("Likely Attack Message Count");
    possibleThreshold = config.getValAsInt("Possible Attack Message Count");
    configured = true;
}