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
    classes.push_back(st);
    classes.push_back(nonst);
    mini(st.id,dfa);
    mini(nonst.id,dfa);
}

Minimization::mini(int id,DFA dfa){
    Minimization::group* cl = get_by_id(id);
    list<int>::iterator it;
    list<DFA_state::line>::iterator lit;
    list<int> remain;
    list<Minimization::group> temp;
    it=cl->states.begin();
    list<DFA_state::line> cline;// = (dfa.get_state(*it))->trans;
    remain.push_back(*it);
    it++;
   for(it;it!=cl->states.end();it++){
      DFA_state* st ;//= dfa.get_state(*it);
      if(lines_equal(cline,st->trans)){
          remain.push_back(*it);
            continue;}
      else{
        list<Minimization::group>::iterator clit;
         bool found = false;
      for(clit=temp.begin();clit!=temp.end();clit++){
          DFA_state* frist; //= dfa.get_state((*clit).states.front());
          if(lines_equal(frist->trans,st->trans)){
           (*clit).states.push_back(*it);
           found = true;
          }
      }
       if(!found){
         Minimization::group newcl;
         list<int> cl;
         newcl.id = num;
         num++;
         cl.push_back(*it);
         temp.push_back(newcl);
       }
      }
   }
   cl->states.clear();
   cl->states.insert(cl->states.end(),remain.begin(),remain.end());
   list<Minimization::group>::iterator clit;
      for(clit=temp.begin();clit!=temp.end();clit++){
        classes.push_back(*clit);
      }
      for(clit=temp.begin();clit!=temp.end();clit++){
        mini((*clit).id,dfa);
      }
}

int Minimization::get_class_of_state(int id){
 list<Minimization::group>::iterator it;
 for(it=classes.begin();it!=classes.end();it++){
   list<int>::iterator iit;
   for(iit=(*it).states.begin();iit!=(*it).states.end();iit++){
       if((*iit)==id){
        return (*it).id;
       }
   }
 }
}


bool Minimization::lines_equal(list<DFA_state::line> t1,list<DFA_state::line> t2){
   bool equ = true;
   list<DFA_state::line>::iterator lit1;
   list<DFA_state::line>::iterator lit2;
   list<DFA_state::line> temp;
   temp.insert(temp.end(),t2.begin(),t2.end());
   list<DFA_state::line> temp2;
   for(lit1=t1.begin();lit1!=t1.end();lit1++){
     DFA_state::line l1 = *lit1;
     bool found = false;
      for(lit2=temp.begin();lit2!=temp.end();lit2++){
        if(((*lit2).input == l1.input)&&(((*lit2).to)->id == (l1.to)->id)){
            found = true;
           break;
        }
        else{
            temp2.push_back(*lit2);
        }
      }
      if(!found){
        equ = false;
        return equ;
      }

      temp.clear();
      if(!temp2.empty()){
      temp.insert(temp.end(),temp2.begin(),temp2.end());
      }
   }
   if(!temp.empty()){
    equ = false;
   }

 return equ;
}

Minimization::group* Minimization::get_by_id(int id){
  list<Minimization::group>::iterator it;
  for(it=classes.begin();it!=classes.end();it++){
     if((*it).id==id){return &(*it);}
  }
}

