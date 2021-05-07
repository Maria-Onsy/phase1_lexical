#include "Tokens.h"

#include <iostream>
#include <fstream>
using std::fstream;
using std::cerr;

Tokens::get_tokens(string file_name,DFA df)
{
 read_from_file(file_name);
 //get tokens
 write_to_file();
}

Tokens::read_from_file(string name)
{
   ifstream file;
    string text;
    file.open(name);
    if(!file){
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    while(getline(file,text)){
        input.push_back(text);
    }

    file.close();
}

Tokens::write_to_file()
{
  fstream file;
  string text;
  file.open("output.txt",ios::out);
  if(!file){
        cerr << "Error: file could not be created" << endl;
        exit(1);
    }
  list<string>::iterator it;
  for(it=output.begin();it!=output.end();it++){
    file<< *it<<endl;
  }
  file.close();
}
