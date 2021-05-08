#include "Check.h"
#include "Tokens.h"
#include "DFA_state.h"

#include <string>
#include <list>
using namespace std;
#include <iostream>

Check::Report_Error(int z){
 bool flag = false;
 list<int> error;
 list<int>::iterator i;
 for(i = error.begin(); i!=error.end(); i++){
  int t = *i;
  if(t == z){flag = false;}
 }
 if(flag){cout << "There is an error in line" << z << endl;}
}

Check::Check(Tokens token,DFA df)
{
/*

int z=0;
list<string> l = token.input;
list<string>:: iterator it;
for(it = l.begin(); it!=l.end(); it++){
 z++;
 bool flag = true;
 string st = *it;
 string accepted = "no";      //to indicate if there is an accepted token (last accepted token)
 string s = "";
 int stop = 0;                //to keep track of index of last accepted token
 DFA_state* state = df.getstates();
 for(int i=0;i<st.length();i++){
  if(st[i]==' '){continue;}
  list<DFA_state::line> q = state->trans;
  list<DFA_state::line>:: iterator k;
  DFA_state::line w = q.front();
  for(k = q.begin(); k!=q.end(); k++){
   if(w.input == st[i]){                    //input is still have path in list
    state = &w.to;
    //q = w.to->trans;
    s = s + st[i];
    break;
    //if(state->stable){accepted = state.name; stop = i;}           Needed
    //else{continue;}
   }
  }
  //else{
    if(accepted != "no"){                         //input have no path and there is an acceptance state
        if (accepted == "id"){                    // if it was an id add it to id table
            list<node>::iterator j;
            for(j = ids.begin(); j!=ids.end(); j++){
                node t = *j;
                if(t.name == s){flag = false;}
            }
            if(flag){node n; n.name = s; ids.push_back(n);}
        }
        token.output.push_back(accepted);       //add it to output
        i = stop+1; s=""; accepted = "no"; state = df.getstates(); continue;
    }
    else{Report_Error(z); i = stop+1; s=""; accepted = "no"; state = df.getstates(); continue;}       //input have no path and no acceptance state, remove char and start again
  //}
 }
}

*/
}
