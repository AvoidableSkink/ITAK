cmake_minimum_required(VERSION 3.6)
project(ITAK)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Analyzer.h
        DenialOfServiceAnalyzer.cpp DenialOfServiceAnalyzer.h
        PortScanAnalyzer.cpp PortScanAnalyzer.h
        Configuration.cpp Configuration.h
        ResultSet.cpp ResultSet.h
        Dictionary.h
        KeyValue.h
        Utils.cpp Utils.h)

add_executable(ITAK main.cpp ${SOURCE_FILES})

set(TEST_FILES
        Testing/testMain.cpp
        Testing/DOSTester.cpp Testing/DOSTester.h
        Testing/PSTester.cpp Testing/PSTester.h
        Testing/ConfigurationTester.cpp Testing/ConfigurationTester.h)

add_executable(Test Testing/testMain.cpp ${SOURCE_FILES} ${TEST_FILES})