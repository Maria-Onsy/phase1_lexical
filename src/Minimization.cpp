#include "Minimization.h"

Minimization::minimize(DFA dfa)
{
    list<DFA_state>::iterator it;
    Minimization::group st;
    Minimization::group nonst;
    list<int> ist;
    list<int> inonst;
    for(it=dfa.allStates.begin();it!=dfa.allStates.end();it++){
        if(it->stable){
          //   ist.push_back(it->id);
        }
        else{
            //inonst.push_back(it->id);
        }
    }
    st.id = 0;
    nonst.id = 1;
    num = 2;
    st.states = ist;
    nonst.states = inonst;
    mini(st,dfa);
    mini(nonst,dfa);
}

Minimization::mini(Minimization::group cl,DFA dfa){
    list<int>::iterator it;
    list<DFA_state::line>::iterator lit;
   for(it=cl.states.begin();it!=cl.states.end();it++){
   // DFA_state* temp = dfa.get_state(*it);

   }
}

