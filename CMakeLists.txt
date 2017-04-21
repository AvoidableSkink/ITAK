cmake_minimum_required(VERSION 3.6)
project(ITAK)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        Analyzer.cpp Analyzer.h
        DenialOfServiceAnalyzer.cpp DenialOfServiceAnalyzer.h
        PortScanAnalyzer.cpp PortScanAnalyzer.h
        Configuration.cpp Configuration.h
        ResultSet.cpp ResultSet.h
        Dictionary.h
        KeyValue.h
        Utils.cpp Utils.h)
add_executable(ITAK ${SOURCE_FILES})