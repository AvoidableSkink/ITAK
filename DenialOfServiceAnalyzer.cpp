//
// Created by klind on 4/18/2017.
//

#include "DenialOfServiceAnalyzer.h"
#include "Utils.h"

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

        //a mess
        //if the ip is not already in the dictionary, add it
        if (!myData.search(ip))
        {
            Dictionary<int, int> newDictionary;
            newDictionary.add(convertStringToInt(time), 1);
            myData.add(ip, newDictionary);
        }
        else
        {
            KeyValue<std::string, Dictionary<int, int>> addressToSum = myData.getByKey(ip);
            Dictionary<int, int> timeToCount = addressToSum.getValue();
            if (timeToCount.search(convertStringToInt(time)))
            {
                int newCount = timeToCount.getByKey(convertStringToInt(time)).getValue()+1;
                timeToCount.updateKey(convertStringToInt(time), newCount);
                myData.updateKey(ip, timeToCount);
            }
            else
            {
                timeToCount.add(convertStringToInt(time), 1);
                myData.updateKey(ip, timeToCount);
            }
        }
    }
}

void DenialOfServiceAnalyzer::setConfiguration(Configuration config) {
    configured = false;
    timeframe = config.getValAsInt("TimeFrame");
    likelyThreshold = config.getValAsInt("Likely Attack Message Count");
    possibleThreshold = config.getValAsInt("Possible Attack Message Count");
    configured = true;
}