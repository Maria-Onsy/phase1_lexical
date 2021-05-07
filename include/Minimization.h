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
        mini(Minimization::group cl,DFA dfa);
};

#endif // MINIMIZATION_H
