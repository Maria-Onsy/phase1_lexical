#ifndef MINIMIZATION_H
#define MINIMIZATION_H

#include "DFA.h"
#include <list>
using namespace std;

class Minimization
{
    public:
       class group{
        public:
         int id;
         list<int> states;
       };
      int num;
      list<group> classes;
      DFA minimal;
      minimize(DFA dfa);

    private:
        mini(int id,DFA dfa);
        int get_class_of_state(int id);
        bool lines_equal(list<DFA_state::line> t1,list<DFA_state::line> t2);
        Minimization::group* get_by_id(int id);
};

#endif // MINIMIZATION_H
