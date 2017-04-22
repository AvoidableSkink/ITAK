//
// Created by klind on 4/20/2017.
//

#include <iostream>
#include "DOSTester.h"
#include "../Configuration.h"
#include "../DenialOfServiceAnalyzer.h"
void DOSTester::testSetConfiguration() {
    std::cout << "DOSTester::testSetConfiguration" << std::endl;

    //set up a configuration
    Configuration myConfiguration;
    myConfiguration.addParamter("TimeFrame", "5");
    myConfiguration.addParamter("Likely Attack Message Count", "500");
    myConfiguration.addParamter("Possible Attack Message Count", "300");

    //call setConfiguration
    DenialOfServiceAnalyzer denialOfServiceAnalyzer;
    denialOfServiceAnalyzer.setConfiguration(myConfiguration);

    if (denialOfServiceAnalyzer.getTimeframe() != 5)
    {
        std::cout << "Failure: expected timeframe value: '5' "
                  << denialOfServiceAnalyzer.getTimeframe() << " found instead" << std::endl;
    }
    if (denialOfServiceAnalyzer.getlikelyThreshold() != 500)
    {
        std::cout << "Failure: expected likelyThreshold value: '500' "
                  << denialOfServiceAnalyzer.getlikelyThreshold() << " found instead" << std::endl;
    }
    if (denialOfServiceAnalyzer.getPossibleThreshold() != 300)
    {
        std::cout << "Failure: expected timeframe value: '300' "
                  << denialOfServiceAnalyzer.getPossibleThreshold() << " found instead" << std::endl;
    }
}