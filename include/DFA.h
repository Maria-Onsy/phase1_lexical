#ifndef DFA_H
#define DFA_H

//#include "Exp_Node.h"
#include "Final_NDFA.h"
#include "DFA_state.h"
#include "NDFA_state.h"
//#include "NDFA.h"

#include <list>
using namespace std;

class DFA
{
public:
    int counter;
    list<DFA_state> allStates;
    int start;
    DFA();
    construct_DFA(Final_NDFA nd);
    list<NDFA_state> getEps(Final_NDFA nd ,int state);
    DFA_state* getstates();
};

#endif // DFA_H
