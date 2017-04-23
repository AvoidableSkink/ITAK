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

    ResultSet resultSet;
    std::vector<std::string> likelyAttackers;
    std::vector<std::string> possibleAttackers;
    std::vector<std::string> attackPeriods;
    std::vector<std::string> timeFrame;
    timeFrame.push_back(std::to_string(timeframe));

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
        fillDOS(ip, time);
    }

    for (int i = 0; i < myData.getCount(); ++i) {
        bool likelyAttacker = false;
        bool possibleAttacker = false;

        KeyValue<std::string, Dictionary<int, int>> addressToSum = myData.getByIndex(i);
        Dictionary<int, int> timeToCount = addressToSum.getValue();

        //go from each time and add the subsequent counts until the limit
        for (int j = 0; j < timeToCount.getCount(); ++j) {
            int messageCount = 0;
            int startTime = timeToCount.getByIndex(j).getKey();
            int limit = startTime + timeframe;
            bool failed = false;
            while (startTime < limit) {
                try {
                    timeToCount.getByKey(startTime);
                }
                catch (std::out_of_range) {
                    failed = true;
                }
                if (!failed)
                    messageCount += timeToCount.getByKey(startTime).getValue();

                startTime++;
                failed = false;
            }

            std::string attackPeriod = std::to_string(startTime-5) + "-" + std::to_string(limit-1);
            //add qualified data to the vectors
            if (messageCount >= likelyThreshold)
            {
                likelyAttackers.push_back(addressToSum.getKey());
                attackPeriods.push_back(attackPeriod);
            }
            else if (messageCount >= possibleThreshold)
            {
                possibleAttackers.push_back(addressToSum.getKey());
                attackPeriods.push_back(attackPeriod);
            }
        }
    }

    resultSet.addResult("Likely Attackers", likelyAttackers);
    resultSet.addResult("Possible Attackers", possibleAttackers);
    resultSet.addResult("Attack Periods", attackPeriods);
    resultSet.addResult("TimeFrame", timeFrame);
    resultSet.print();
    return resultSet;
}

void DenialOfServiceAnalyzer::setConfiguration(Configuration config) {
    configured = false;
    timeframe = config.getValAsInt("TimeFrame");
    likelyThreshold = config.getValAsInt("Likely Attack Message Count");
    possibleThreshold = config.getValAsInt("Possible Attack Message Count");
    configured = true;
}

void DenialOfServiceAnalyzer::fillDOS(std::string ip, std::string time) {
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

int DenialOfServiceAnalyzer::sumAllMessageCounts() {

}