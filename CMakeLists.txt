cmake_minimum_required(VERSION 3.12)
project(flightgearInterpreter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread -lpthread")
add_executable(flightgearInterpreter
        main.cpp interpreter/Lexer.cpp interpreter/Lexer.h interpreter/Parser.cpp
        interpreter/Parser.h Expressions/Expression.h
        Utilities/Utils.cpp Utilities/Utils.h interpreter/SymbolsTable.cpp interpreter/SymbolsTable.h TCPconnection/DataWriterClient.cpp TCPconnection/DataWriterClient.h
        Utilities/ShuntingYard.cpp Utilities/ShuntingYard.h Expressions/UnaryExpression.h Expressions/BinaryExpression.h Expressions/Plus.h Expressions/Minus.h Expressions/Div.h
        Expressions/Multi.h Expressions/Neg.h Expressions/BooleanExpression.h Expressions/Num.h Commands/OpenDataServer.h Expressions/Greater.h Expressions/GreaterEquals.h Expressions/Lesser.h
        Expressions/LesserEquals.h Expressions/Equals.h Expressions/NotEquals.h Commands/Command.h Commands/ConditionCommand.h Commands/IfCommand.h
        Commands/WhileCommand.h Commands/VarCommand.h Expressions/Var.h Commands/PrintStringCommand.h Commands/SleepCommand.h
        Commands/PrintExpressionCommand.h Commands/AssignmentCommand.h Commands/ConnectCommand.h TCPconnection/TcpServer.cpp TCPconnection/TcpServer.h TCPconnection/DataServer.cpp TCPconnection/DataServer.h)
