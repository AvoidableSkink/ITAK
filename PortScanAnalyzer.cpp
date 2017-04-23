//
// Created by klind on 4/18/2017.
//

#include "PortScanAnalyzer.h"
#include "Utils.h"


PortScanAnalyzer::PortScanAnalyzer() {
    configured = false;
}

ResultSet PortScanAnalyzer::run(std::istream & in) {
    //if the analyzer is not configured, return an empty ResultSet
    if (!configured)
    {
        ResultSet empty;
        return empty;
    }

    std::vector<std::string> likelyAttackers;
    std::vector<std::string> possibleAttackers;
    std::vector<std::string> portCount;
    portCount.push_back(std::to_string(likelyThreshold));
    portCount.push_back(std::to_string(possibleThreshold));

    std::string time, ip, src, des;
    while (!in.eof())
    {
        std::string line;
        std::getline(in, line);

        std::string myVals[4];
        if (split(line, ',', myVals, 4))
        {
            time = myVals[0];
            ip = myVals[1];
            src = myVals[2];
            des = myVals[3];
        }
        //fill the dictionary
        if (!myData.search(ip))
        {
            std::vector<int> ports;
            ports.push_back(convertStringToInt(des));
            myData.add(ip, ports);
        }
        else
        {
            std::vector<int> updatedList = myData.getByKey(ip).getValue();

            bool found = false;
            for (int i = 0; i < updatedList.size(); ++i) {
                if (updatedList[i] == convertStringToInt(des))
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                updatedList.push_back(convertStringToInt(des));
                myData.updateKey(ip, updatedList);
            }
        }
    }
}

void PortScanAnalyzer::setConfiguration(Configuration config) {
    configured = false;
    likelyThreshold = config.getValAsInt("Likely Attack Port Count");
    possibleThreshold = config.getValAsInt("Possible Attack Port Count");
    configured = true;
}