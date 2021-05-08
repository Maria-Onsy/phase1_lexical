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
    DFA_state tmpstate;
    list<DFA_state> allStates;
    int start;
    DFA();
    construct_DFA(Final_NDFA nd);
    list<NDFA_state> getEps(Final_NDFA nd ,int state);
    list<DFA_state> getstates();
    bool exists (list<int>);
    //DFA_state getexists(list<int>);
};

#endif // DFA_H
