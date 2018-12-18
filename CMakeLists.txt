cmake_minimum_required(VERSION 3.12)
project(flightgearInterpreter)

set(CMAKE_CXX_STANDARD 14)

add_executable(flightgearInterpreter
        main.cpp DataReaderServer.cpp DataReaderServer.h Utils.cpp Utils.h SymbolsTable.cpp SymbolsTable.h)
