//
// Created by klind on 4/20/2017.
//

#include <iostream>
#include "ConfigurationTester.h"
#include "DOSTester.h"

int main() {
    ConfigurationTester configurationTester;
    configurationTester.testGetValAsString();
    configurationTester.testGetValAsDouble();
    configurationTester.testGetValAsInt();

    DOSTester dosTester;
    dosTester.testSetConfiguration();
    dosTester.testRun();
}