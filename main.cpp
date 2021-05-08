#include <iostream>

#include "Exp_Node.h"
#include "Rules.h"
#include "Final_NDFA.h"
#include "DFA.h"
#include "Tokens.h"
#include "Minimization.h"
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
    list<string> ::iterator it;
    for(it=rules.priority.begin();it!=rules.priority.end();it++){
           // Exp_Node t = *it;
    cout<< '\t' << *it;
    cout<<'\n';
    //cout<< '\t' << t.value;
     //   cout<<'\n';
    }*/

    Final_NDFA ndfa = Final_NDFA();
    ndfa.construct_NDFA(rules.expressions);

/*NDFA_state* b = ndfa.get_state(ndfa.start);
   // cout<<'\t'<<ndfa.start;
     cout <<"\nstate\n";
        list<NDFA_state::line> :: iterator tst;
        for(tst=b->trans.begin();tst!=b->trans.end();tst++){
            cout<< "input\n";
            NDFA_state::line ln = *tst;
            cout<< '\t'<<ln.input;
            cout<<'\n';
            cout<<"to:  ";
            cout<<'\t'<<ln.to;
            cout<< '\n';
            cout<<'\t'<<b->stable;
            cout<<'\n';
            if(b->stable){cout<<'\t'<<b->name;}
        }
*/
    DFA dfa;
   dfa.construct_DFA(ndfa,rules);

 /*   list<DFA_state> b = dfa.getstates();
     cout <<"\nstate\n";
        list<DFA_state> :: iterator state;
        list<DFA_state::line> :: iterator tst;
        for(state=b.begin();state!=b.end();state++){
            for(tst=state->trans.begin();tst!=state->trans.end();tst++){
                cout<<"ids:\n";
                list<int>::iterator ttt;
                 for(ttt=(*state).ids.begin();ttt!=(*state).ids.end();ttt++){
                    cout<<'\t'<<(*ttt);
                 }
                 cout<<"\nid\n";
                 cout<<'\t'<<state->id;
                cout<< "\ninput\n";
                DFA_state::line ln = *tst;
                cout<< '\t'<<ln.input;
                cout<< '\n';
                cout<<"to id\n";
                cout<< '\t'<<(ln.to)->id;
                cout<< '\n';
                cout<<"stability\n";
                cout<<'\t'<<state->stable;
                cout<<'\n';
                cout<<"name\n";
                cout<<'\t'<<state->name;
                cout<<'\n';
            }
            if(state->trans.size()==0){
                 cout<<"\nid\n";
                 cout<<'\t'<<state->id;
                cout<<"\nstability\n";
                cout<<'\t'<<state->stable;
                cout<<'\n';
                cout<<"name\n";
                cout<<'\t'<<state->name;
                cout<<'\n';
            }
        }
*/

        Minimization mini;
        mini.minimize(dfa);

//    Tokens tk;
    return 0;
}
