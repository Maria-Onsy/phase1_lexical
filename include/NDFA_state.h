#ifndef NDFA_STATE_H
#define NDFA_STATE_H

#include <list>
#include <string>
using namespace std;


class NDFA_state
{
    public:
       class line{
         public:
           int to;
           char input;
       };
       int id;
       bool stable;
       string name;
       list<line> trans;
};



#endif // NDFA_STATE_H
