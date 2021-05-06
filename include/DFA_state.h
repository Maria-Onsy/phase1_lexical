#ifndef DFA_STATE_H
#define DFA_STATE_H

#include <list>
#include <string>
#include "NDFA_state.h"
using namespace std;


class DFA_state
{
public:
    class line {
    public:
        list<int> to;
        char input;
    };

    list<NDFA_state*> ids;
    bool stable;
    list<line> trans;
};



#endif // DFA_STATE_H
