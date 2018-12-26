#include "DataServer.h"

/* Null, because instance will be initialized on demand. */
DataServer *DataServer::instance = 0;


DataServer *DataServer::getInstance(int serverPort)
{

    //singleton instance:
    if (instance == NULL)
    {
        instance = new DataServer(serverPort);
    }
    return instance;
}

DataServer *DataServer::getInstance()
{

    //singleton instance:
    if (instance == NULL)
    {
        return  NULL;
    }
    else return instance;
}

void DataServer::destroyInstance(){
    //delete singleton instance
    if(instance != 0)
    {
        delete instance;
        instance = 0;
    }
}

DataServer::DataServer(int serverPort){

    this->serverPort = serverPort;
    this->endServerFlag = false;


};

void DataServer::openServer(){
    this->socketId = TcpServer::acceptConnection(this->serverPort);
}

void DataServer::closeServer(){

    TcpServer::closeSocket(this->socketId);

}

void DataServer::receiveOnce(){

    std::string line = TcpServer::readLine(this->socketId);
    updateSymbolsValues(line);

}

void DataServer::startReceive(){

    while(!endServerFlag){

        std::string line = TcpServer::readLine(this->socketId);
        updateSymbolsValues(line);
    }

}

void DataServer::stopReceive() {
    this->endServerFlag = true;
}

void DataServer::updateSymbolsValues(std::string dataStr){

    //separate values by csv format from string
    std::vector<std::string> valuesVec = Utils::explode(dataStr,',');

    for (int i = 0; i < valuesVec.size(); ++i) {

        if(valuesVec[i].empty()) continue;

        //the symbol name as exist in the simulator paths
        string symbolName = SymbolsTable::paths[i];

        SymbolsTable::getInstance() -> setSymbol(symbolName, std::stod(valuesVec[i]), symbolName);

    }

}

DataServer::~DataServer(){
    closeServer();

}

