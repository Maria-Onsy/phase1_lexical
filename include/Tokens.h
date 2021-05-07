#ifndef TOKENS_H
#define TOKENS_H

#include "DFA.h"
#include <string>
#include <list>
using namespace std;

class Tokens
{
    public:
        list<string> input;
        list<string> output;
        get_tokens(string file_name,DFA df);

    private:
        read_from_file(string name);
        write_to_file();
};

#endif // TOKENS_H
