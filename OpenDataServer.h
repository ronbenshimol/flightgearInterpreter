/*                     .ed"""" """$$$$be.
                   -"           ^""**$$$e.
                 ."                   '$$$c
                /                      "4$$b
               d  3                      $$$$
               $  *                   .$$$$$$
              .$  ^c           $$$$$e$$$$$$$$.
              d$L  4.         4$$$$$$$$$$$$$$b
              $$$$b ^ceeeee.  4$$ECL.F*$$$$$$$
  e$""=.      $$$$P d$$$$F $ $$$$$$$$$- $$$$$$
 z$$b. ^c     3$$$F "$$$$b   $"$$$$$$$  $$$$*"      .=""$c
4$$$$L        $$P"  "$$b   .$ $$$$$...e$$        .=  e$$$.
^*$$$$$c  %..   *c    ..    $$ 3$$$$$$$$$$eF     zP  d$$$$$
  "**$$$ec   "   %ce""    $$$  $$$$$$$$$$*    .r" =$$$$P""
        "*$b.  "c  *$e.    *** d$$$$$"L$$    .d"  e$$***"
          ^*$$c ^$c $$$      4J$$$$$% $$$ .e*".eeP"
             "$$$$$$"'$=e....$*$$**$cz$$" "..d$*"
               "*$$$  *=%4.$ L L$ P3$$$F $$$P"
                  "$   "%*ebJLzb$e$$$$$b $P"
                    %..      4$$$$$$$$$$ "
                     $$$e   z$$$$$$$$$$%
                      "*$c  "$$$$$$$P"
                       ."""*$$$$$$$$bc
                    .-"    .$***$$$"""*e.
                 .-"    .e$"     "*$c  ^*b.
          .=*""""    .e$*"          "*bc  "*$e..
        .$"        .z*"               ^*$e.   "*****e.
        $$ee$c   .d"                     "*$.        3.
        ^*$E")$..$"                         *   .ee==d%
           $.d$$$*                           *  J$$$e*
            """""    ENTER AT YOU OWN RISK!   "$$$"

*/

#ifndef FLIGHTGEARINTERPRETER_OPENDATASERVER_H
#define FLIGHTGEARINTERPRETER_OPENDATASERVER_H

#include "BinaryExpression.h"
#include "DataServer.h"
#include "SymbolsTable.h"
#include "Command.h"
#include <thread>

class OpenDataServer : public Command {

    Expression *portExpression;
    Expression *readePsExpression;
    std::thread serverThread;

public:

    OpenDataServer(Expression *portExp, Expression *readsPs){

        this->portExpression = portExp;
        this->readePsExpression = readsPs;

    }

    double execute(){

        int port = (int)portExpression->calculate();
        int numOfReads = (int)readePsExpression->calculate();

        DataServer::getInstance(port);
        DataServer::getInstance()->openServer();
        DataServer::getInstance()->receiveOnce();

        //starting receiving data from the simulator in thread
        serverThread = std::thread([](){
            DataServer::getInstance()->startReceive();
        });



        return 0;

    }

public:

    ~OpenDataServer() override {

        delete portExpression;
        delete readePsExpression;

        //turn on the flag of stop recieving data in the server
        DataServer::getInstance()->stopReceive();

        //wait for the thread to end
        serverThread.join();

        //destroy the instance of the server
        DataServer::destroyInstance();
    }

};


#endif //FLIGHTGEARINTERPRETER_OPENDATASERVER_H
