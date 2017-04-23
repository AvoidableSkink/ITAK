#include <iostream>
#include <fstream>
#include "Configuration.h"
#include "PortScanAnalyzer.h"

int main() {
    Configuration myConfiguration;
    myConfiguration.addParamter("Likely Attack Port Count", "500");
    myConfiguration.addParamter("Possible Attack Port Count", "300");

    PortScanAnalyzer portScanAnalyzer;
    portScanAnalyzer.setConfiguration(myConfiguration);

    std::ifstream inputStream("../SampleData.csv");
    ResultSet results = portScanAnalyzer.run(inputStream);
    results.print();
}