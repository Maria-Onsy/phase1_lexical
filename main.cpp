#include <iostream>

#include "Exp_Node.h"
#include "Rules.h"
#include "Final_NDFA.h"
#include "DFA.h"
#include "Tokens.h"
#include "Minimization.h"
#include "check.h"
using namespace std;

int main()
{
    Rules rules;
    rules.path="Rules.txt";
    rules.read_from_file();
    rules.convert_to_expressions();

    Final_NDFA ndfa = Final_NDFA();
    ndfa.construct_NDFA(rules.expressions);

    DFA dfa;
    dfa.construct_DFA(ndfa,rules);

    Minimization mini;
    mini.minimize(dfa);

    Tokens tk;
    tk.read_from_file("Input.txt");
    check ch;
    ch.Check(tk,mini.minimal);

    return 0;
}
