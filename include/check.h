#ifndef CHECK_H
#define CHECK_H

#include "Tokens.h"
#include "DFA.h"
#include <string>
#include <list>
using namespace std;

class Check
{
     public:
       class node{
         public:
           string type;
           float value;
           string name;
       };
       list<node> ids;

    private:
        Report_Error(int z);
        Check(Tokens token, DFA df);
};

#endif // CHECK_H
