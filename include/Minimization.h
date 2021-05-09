#ifndef MINIMIZATION_H
#define MINIMIZATION_H

#include "DFA.h"
#include <list>
using namespace std;

class Minimization
{
    public:
       class line{
          public:
            string input;
            int to;
        };
       class group{
        public:
         int id;
         list<int> states;
         list<Minimization::line> trans;
       };
      int num;
      list<group> classes;
      list<string> table;

      DFA minimal;
      minimize(DFA dfa);

    private:
        mini(int id,DFA dfa);
        int get_class_of_state(int id);
        bool lines_equal(list<DFA_state::line> t1,list<DFA_state::line> t2);
        Minimization::group* get_by_id(int id);
        print_table(DFA dfa);
        write_to_file();
        get_states(DFA dfa,int id,list<DFA_state::line> lines);
        bool contain(list<DFA_state::line> lst,DFA_state::line l);
};

#endif // MINIMIZATION_H
