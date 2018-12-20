cmake_minimum_required(VERSION 3.12)
project(flightgearInterpreter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread -lpthread")
add_executable(flightgearInterpreter
        main.cpp DataReaderServer.cpp DataReaderServer.h Lexer.cpp Lexer.h Parser.cpp
        Parser.h Expression.h
        main.cpp DataReaderServer.cpp DataReaderServer.h Utils.cpp Utils.h SymbolsTable.cpp SymbolsTable.h DataWriterClient.cpp DataWriterClient.h ShuntingYard.cpp ShuntingYard.h UnaryExpression.h BinaryExpression.h Plus.h Minus.h Div.h)
