#include <iostream>

#include "Exp_Node.h"
#include "Rules.h"
#include "Final_NDFA.h"
#include "DFA.h"
#include "Tokens.h"
using namespace std;

int main()
{
    Rules rules;
    rules.path="test.txt";
    rules.read_from_file();
    rules.convert_to_expressions();

    //print expressions
    /*cout<<"expresions";
    cout<<'\n';
    list<Exp_Node> ::iterator it;
    for(it=rules.expressions.begin();it!=rules.expressions.end();it++){
            Exp_Node t = *it;
    cout<< '\t' << t.name;
    cout<<'\n';
    cout<< '\t' << t.value;
        cout<<'\n';
    }*/

    Final_NDFA ndfa = Final_NDFA();
    ndfa.construct_NDFA(rules.expressions);

    DFA dfa;
    dfa.construct_DFA(ndfa);

//    Tokens tk;
    return 0;
}
