#ifndef FLIGHTGEARINTERPRETER_CONNECTCOMMAND_H
#define FLIGHTGEARINTERPRETER_CONNECTCOMMAND_H


#include <string>
#include "Command.h"
#include "Expression.h"
#include "DataWriterClient.h"
#include "SymbolsTable.h"

class ConnectCommand : public Command {

    std::string serverIP;
    Expression *serverPort;


public:
    ConnectCommand(std::string serverIP, Expression *serverPort) : serverIP(move(serverIP)), serverPort(serverPort) {}

    double execute() override {

        auto client = new DataWriterClient(this->serverIP,(uint16_t)this->serverPort->calculate());
        client->open();
        SymbolsTable::getInstance()->setClient(client);

        return 0;
    }


};


#endif //FLIGHTGEARINTERPRETER_CONNECTCOMMAND_H
