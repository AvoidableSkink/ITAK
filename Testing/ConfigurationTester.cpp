//
// Created by klind on 4/21/2017.
//

#include <iostream>
#include "ConfigurationTester.h"
#include "../Configuration.h"

void ConfigurationTester::testGetValAsString() {
    std::cout << "ConfigurationTester::testGetValAsString" << std::endl;

    //set up a configuration
    Configuration myConfiguration;
    myConfiguration.addParamter("TimeFrame", "5");
    myConfiguration.addParamter("Likely Attack Message Count", "500");
    myConfiguration.addParamter("Possible Attack Message Count", "300");

    if (myConfiguration.getValAsString("TimeFrame") != "5")
    {
        std::cout << "Failure: with key 'TimeFrame' expected output: '5' "
                  << myConfiguration.getValAsString("TimeFrame") << " found instead" << std::endl;
    }

    if (myConfiguration.getValAsString("Likely Attack Message Count") != "500")
    {
        std::cout << "Failure: with key 'Likely Attack Message Count' expected output: '500' "
                  << myConfiguration.getValAsString("Likely Attack Messsage Count") << " found instead" << std::endl;
    }

    if (myConfiguration.getValAsString("Possible Attack Message Count") != "300")
    {
        std::cout << "Failure: with key 'Possible Attack Message Count' Expected output: '300' "
                  << myConfiguration.getValAsString("Possible Attack Message Count") << " found instead" << std::endl;
    }
}

void ConfigurationTester::testGetValAsDouble() {
    std::cout << "ConfigurationTester::testGetValAsDouble" << std::endl;

    //set up a configuration
    Configuration myConfiguration;
    myConfiguration.addParamter("TimeFrame", "5");
    myConfiguration.addParamter("Likely Attack Message Count", "500");
    myConfiguration.addParamter("Possible Attack Message Count", "300");

    if (myConfiguration.getValAsDouble("TimeFrame") != 5)
    {
        std::cout << "Failure: with key 'TimeFrame' expected output the double '5' "
                  << myConfiguration.getValAsDouble("TimeFrame") << " found instead" << std::endl;
    }

    if (myConfiguration.getValAsDouble("Likely Attack Message Count") != 500)
    {
        std::cout << "Failure: with key 'Likely Attack Message Count' expected output: '500' "
                  << myConfiguration.getValAsDouble("Likely Attack Messsage Count") << " found instead" << std::endl;
    }

    if (myConfiguration.getValAsDouble("Possible Attack Message Count") != 300)
    {
        std::cout << "Failure: with key 'Possible Attack Message Count' Expected output: '300' "
                  << myConfiguration.getValAsDouble("Possible Attack Message Count") << " found instead" << std::endl;
    }
}

void ConfigurationTester::testGetValAsInt() {
    std::cout << "ConfigurationTester::testGetValAsInt" << std::endl;

    //set up a configuration
    Configuration myConfiguration;
    myConfiguration.addParamter("TimeFrame", "5");
    myConfiguration.addParamter("Likely Attack Message Count", "500");
    myConfiguration.addParamter("Possible Attack Message Count", "300");

    if (myConfiguration.getValAsInt("TimeFrame") != 5)
    {
        std::cout << "Failure: with key 'TimeFrame' expected output the int '5' "
                  << myConfiguration.getValAsInt("TimeFrame") << " found instead" << std::endl;
    }

    if (myConfiguration.getValAsInt("Likely Attack Message Count") != 500)
    {
        std::cout << "Failure: with key 'Likely Attack Message Count' expected output: '500' "
                  << myConfiguration.getValAsInt("Likely Attack Messsage Count") << " found instead" << std::endl;
    }

    if (myConfiguration.getValAsInt("Possible Attack Message Count") != 300)
    {
        std::cout << "Failure: with key 'Possible Attack Message Count' Expected output: '300' "
                  << myConfiguration.getValAsInt("Possible Attack Message Count") << " found instead" << std::endl;
    }
}