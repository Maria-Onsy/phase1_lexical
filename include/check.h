#ifndef CHECK_H
#define CHECK_H

#include "Tokens.h"
#include "DFA.h"
#include <string>
#include <list>
using namespace std;

class check
{
     public:
       class node{
         public:
           string type;
           float value;
           string name;
       };
       list<node> ids;
       Check(Tokens token, DFA df);

    private:
        Report_Error(int z);

};

#endif // CHECK_H
