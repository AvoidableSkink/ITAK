//
// Created by klind on 4/20/2017.
//

#include <iostream>
#include <fstream>
#include "PSTester.h"
#include "../Configuration.h"
#include "../PortScanAnalyzer.h"

void PSTester::testSetConfiguration() {
    std::cout << "PSTester::testSetConfiguration" << std::endl;

    //set up a configuration
    Configuration myConfiguration;
    myConfiguration.addParamter("Likely Attack Port Count", "500");
    myConfiguration.addParamter("Possible Attack Port Count", "300");

    //call setConfiguration
    PortScanAnalyzer portScanAnalyzer;
    portScanAnalyzer.setConfiguration(myConfiguration);

    if (portScanAnalyzer.getLikelyThreshold() != 500)
    {
        std::cout << "Failure: expected likelyThreshold value: '500' "
                  << portScanAnalyzer.getLikelyThreshold() << " found instead" << std::endl;
    }
    if (portScanAnalyzer.getPossibleThreshold() != 300)
    {
        std::cout << "Failure: expected timeframe value: '300' "
                  << portScanAnalyzer.getPossibleThreshold() << " found instead" << std::endl;
    }

    Configuration newConfiguration;
    newConfiguration.addParamter("Likely Attack Port Count", "500");
    newConfiguration.addParamter("bad", "300");

    PortScanAnalyzer portScanAnalyzer1;
    try {
        portScanAnalyzer1.setConfiguration(newConfiguration);
        std::cout << "Failure: Inadequate configuration set." << std::endl;
    }
    catch (std::out_of_range){}
}

void PSTester::testRun() {
    std::cout << "DOSTester::testRun" << std::endl;

    //set up a configuration
    Configuration myConfiguration;
    myConfiguration.addParamter("Likely Attack Port Count", "500");
    myConfiguration.addParamter("Possible Attack Port Count", "300");

    PortScanAnalyzer portScanAnalyzer;
    portScanAnalyzer.setConfiguration(myConfiguration);

    std::ifstream inputStream("../SampleData.csv");
    ResultSet results = portScanAnalyzer.run(inputStream);
    results.print();
}