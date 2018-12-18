cmake_minimum_required(VERSION 3.12)
project(flightgearInterpreter)

set(CMAKE_CXX_STANDARD 14)

add_executable(flightgearInterpreter
        main.cpp DataReaderServer.cpp DataReaderServer.h Command.h Lexer.cpp Lexer.h Parser.cpp
        Parser.h DemoCommand.cpp DemoCommand.h Expression.cpp Expression.h
        main.cpp DataReaderServer.cpp DataReaderServer.h Utils.cpp Utils.h SymbolsTable.cpp SymbolsTable.h)
