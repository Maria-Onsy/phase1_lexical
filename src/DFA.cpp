#include "DFA.h"
#include<iostream>
#include<queue>
#include "NDFA_state.h"


DFA::DFA()
{
   counter = 0;
}

DFA::construct_DFA(Final_NDFA nd) {

	int start = nd.start;
	list<NDFA_state> startl = getEps(nd ,start);

	startl.unique();   // remove dublicate states
	//list<DFA_state :: line> :: iterator prin;
	// for(prin=s.trans.begin();prin!=s.trans.end();++prin){
        //cout<<prin->input <<" ";
   // }
	DFA_state s;
    list<int> startints;///
    list<NDFA_state> ::iterator getints;///
    for(getints=startl.begin();getints!=startl.end();++getints){///
        startints.push_back((*getints).id);///
    }///
    startints.sort();
	//assign the list of start states to ids list of start deterministic state
    s.ids .insert(s.ids.end(), startints.begin(), startints.end());
    /////allStates.push_back(s);   /////
	list<NDFA_state> ::iterator it;

    queue<DFA_state> q;
    q.push(s);
while(!q.empty()){

    s = q.front();
    q.pop();

	list<char> validinputs;   //inputs from the current deter. state
    list<NDFA_state> ll;      // state of non deter. states of the current deter. state(s)

    list<NDFA_state> startints2;///
    list<int> ::iterator getints;///
    for(getints=s.ids.begin();getints!=s.ids.end();++getints){///
        startints2.push_back(*nd.get_state((*getints)));///
    }///
    ll.insert(ll.end(), startints2.begin(), startints2.end());

	//extract all possible inputs from the start state s
	for (it = ll.begin(); it != ll.end(); ++it) {
		list<NDFA_state :: line> ::iterator lineit;
		list<NDFA_state::line> linel;
		linel.insert(linel.end(), (*it).trans.begin(), (*it).trans.end());
		for (lineit = linel.begin(); lineit != linel.end(); ++lineit) {
			if (lineit->input != ' ') {
				validinputs.push_back(lineit->input);
			}
		}
	}

	validinputs.unique();

            if(validinputs.empty()){  // if final state
                    // check if the deter. state is stable or not
                        list<int> :: iterator isstable;    ////
                        s.stable=false;
                        for (isstable = s.ids.begin(); isstable != s.ids.end(); ++isstable) {

                            if(nd.get_state(*isstable)->stable){
                            s.stable=true;
                            cout<<"am here"<<endl;
                        }
                    }
                 allStates.push_back(s);
                 counter++;

            }
            else{
            list<char> ::iterator inputit;
			for (inputit = validinputs.begin(); inputit != validinputs.end(); ++inputit) {  // loop over valid inputs

                list<int> ::iterator nextit;     ///
                list <int> currentids = s.ids; ///
                list<int> next;///
                for (nextit = currentids.begin(); nextit != currentids.end(); ++nextit) {  // iterate over NDFS nodes of the current DFA node

                    list<NDFA_state::line> ::iterator lineit;
                    list< NDFA_state::line> linel = nd.get_state(*nextit)->trans; ///
                    for (lineit = linel.begin(); lineit != linel.end(); ++lineit) {

                        if ((*lineit).input == *inputit) {

                            NDFA_state tmp = *nd.get_state(lineit->to);
                            next.push_back(tmp.id);///

                            list<NDFA_state> ep = getEps(nd, lineit->to);

                            list<NDFA_state> ::iterator epit;

                            for (epit = ep.begin(); epit != ep.end(); ++epit) {  // loop over eps transitions from the destination state and add them to next
                                next.push_back((*epit).id);  ///
                        }
                    }
                }
            }

                    if (!next.empty()) {
                        next.unique();

                        next.sort();

                        DFA_state::line newl;

                         newl.input = *inputit;

                        if(exists(next) == true){

                            //DFA_state ex = getexists(next);
                            newl.to = &tmpstate;
                        }
                        else{
                            DFA_state news;   // next state after entering inputit to the start state
                            news.ids .insert(news.ids .end(), next.begin(), next.end());
                            newl.to = &news;
                            q.push(news);
                            counter++;
                        }
                        // check if the deter. state is stable or not
                        list<int> :: iterator isstable;    ////
                        s.stable=false;
                        for (isstable = s.ids.begin(); isstable != s.ids.end(); ++isstable) {

                            if(nd.get_state(*isstable)->stable){
                            s.stable=true;
                            cout<<"am here"<<endl;
                        }
                    }
                        s.trans.push_back(newl);

                        allStates.push_back(s);

                    }

                }

}


        }
/////

}

list<NDFA_state> DFA::getEps(Final_NDFA nd, int state) {
	list<NDFA_state> eps;
	queue<int> q;
	q.push(state);
	while (!q.empty()) {
		int current = q.front();
        q.pop();
		NDFA_state curr = *nd.get_state(current);
		eps.push_back(curr);
		std::list<NDFA_state::line> ::iterator it;
		list<NDFA_state::line> l = curr.trans;
		for (it = l.begin(); it != l.end(); ++it) {
			if (it->input == ' ') {
				q.push(it->to);
			}
		}
	}

	return eps;
}

    list<DFA_state> DFA ::getstates(){
    return allStates;
}

bool DFA ::exists (list<int> next){
    list<DFA_state> :: iterator stateit;
    for(stateit =allStates.begin(); stateit != allStates.end(); ++stateit){
        list<int>:: iterator l1,l2;
        bool flag = true;
        for(l1=next.begin(),l2=(*stateit).ids.begin() ; l1!=next.end(),l2!=(*stateit).ids.end() ; ++l1 , ++ l2){
            if(*l1!=*l2){
                flag=false;
            }
        }
        if(flag == true && l1== next.end() && l2==(*stateit).ids.end()){
            tmpstate=*stateit;

            return true;
        }

    }
    return false;
}
