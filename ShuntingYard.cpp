
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
            """""    ההעתקה על אחריותכם בלבד!  "$$$"

*/


#include "ShuntingYard.h"

stack<string> ShuntingYard::convertToPostfix(string infix){

    istringstream iss(infix);
    vector<string> tokens;//store the tokens in vector
    while(iss)
    {
        string temp;
        iss >>temp;
        tokens.push_back(temp);
    }
    vector<string> outputList;//output vector
    stack<string> s;//main stack

    //operator: +, -, *, /, ^, ()
    for(unsigned int i = 0; i < tokens.size(); i++)  //read from right to left
    {
        if(TryParse(tokens[i]))
        {
            outputList.push_back(tokens[i]);
        }
        else if(tokens[i] == "(")
        {
            s.push(tokens[i]);
        }
        else if(tokens[i] == ")")
        {
            while(!s.empty() && s.top() != "(")
            {
                outputList.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else if(isOperator(tokens[i]) == true)
        {
            while(!s.empty() && Priority(s.top()) >= Priority(tokens[i]))
            {
                outputList.push_back(s.top());
                s.pop();
            }
            s.push(tokens[i]);
        }
        else if(tokens[i].length()>0)
        {
            //the token is a symbol
            outputList.push_back(tokens[i]);
        }
    }
    //pop any remaining operators from the stack and insert to outputlist
    while(!s.empty())
    {
        outputList.push_back(s.top());
        s.pop();
    }

    stack<string> postfixStack;

    for(unsigned int i = 0; i < outputList.size(); i++)
    {
        postfixStack.push(outputList[i]);
        //cout<<outputList[i];
    }

    return postfixStack;

}


bool ShuntingYard::TryParse(const std::string &symbol)
{
    bool isNumber = false;
    for(unsigned int i = 0; i < symbol.size(); i++)
    {
        if(!isdigit(symbol[i]))
        {
            isNumber = false;
        }
        else
        {
            isNumber = true;
        }
    }
    return isNumber;
}
int ShuntingYard::Priority(const std::string &c)
{
    if(c == "^")
    {
        return 3;
    }
    if(c == "*" || c == "/")
    {
        return 2;
    }
    if(c== "+" || c == "-")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool ShuntingYard::isOperator(const std::string &c)
{
    return (c == "+" || c == "-" || c == "*" || c == "/" || c == "^");
}