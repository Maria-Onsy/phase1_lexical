#include "DFA.h"
#include<iostream>
#include<queue>
#include "NDFA_state.h"
int counter = 0;

DFA::construct_DFA(Final_NDFA nd) {

	int start = nd.start;
	list<NDFA_state*> startl = getEps(nd ,start);
	startl.unique();   // remove dublicate states
	DFA_state* s;
    s->ids .insert(s->ids.end(), startl.begin(), startl.end());

	list<NDFA_state*> ::iterator it;

    queue<DFA_state*> q;
    q.push(s);
while(!q.empty()){
    s = q.front();
    q.pop();
	list<char> validinputs;   //inputs from the start state
	for (it = startl.begin(); it != startl.end(); ++it) {
		list<NDFA_state :: line> ::iterator lineit;
		list<NDFA_state::line> linel;
		linel.insert(linel.end(), (*it)->trans.begin(), (*it)->trans.end());
		for (lineit = linel.begin(); lineit != linel.end(); ++lineit) {
			if (lineit->input != ' ') {
				validinputs.push_back(lineit->input);
			}
		}
	}

	validinputs.unique();



		list<NDFA_state*> ::iterator nextit;
		list < NDFA_state*> currentids = s->ids;
		for (nextit = currentids.begin(); nextit != currentids.end(); ++nextit) {  // iterate over NDFS nodes of the current DFA node
			list<char> ::iterator inputit;
			for (inputit = validinputs.begin(); inputit != validinputs.end(); ++inputit) {  // loop over valid inputs
				list<NDFA_state*> next;
				list<NDFA_state::line> ::iterator lineit;
				list< NDFA_state::line> linel = (*nextit)->trans;
				for (lineit = linel.begin(); lineit != linel.end(); ++lineit) {
					if (lineit->input == *inputit) {
						NDFA_state* tmp = nd.get_state(lineit->to);
						next.push_back(tmp);
						list<NDFA_state*>ep = getEps(nd, lineit->to);
						list<NDFA_state*> ::iterator epit;
						for (epit = ep.begin(); epit != ep.end(); ++epit) {  // loop over eps transitions from the destination state and add them to next
							next.push_back(*epit);
					}
				}
			}
				if (!next.empty()) {
					next.unique();
					DFA_state::line newl;
					DFA_state* news;   // next state after entering inputit to the start state
					//news->ids = next;
					news->ids .insert(news->ids .end(), next.begin(), next.end());

					newl.input = *inputit;
					list<NDFA_state*> ::iterator tmpit;
					for (tmpit = next.begin(); tmpit != next.end(); ++tmpit) {   // add destination states to the new line
						newl.to.push_back((*tmpit)->id);
					}
					s->trans.push_back(newl);
                    q.push(news);
				}

		}

	}


}
	// make other DFA states starting from S state


}
list<NDFA_state*> DFA::getEps(Final_NDFA nd, int state) {
	list<NDFA_state*> eps;
	queue<int> q;
	q.push(state);
	while (!q.empty()) {
		int current = q.front();
        q.pop();
		NDFA_state* curr = nd.get_state(current);
		eps.push_back(curr);
		std::list<NDFA_state::line> ::iterator it;
		list<NDFA_state::line> l = curr->trans;
		for (it = l.begin(); it != l.end(); ++it) {
			if (it->input == ' ') {
				q.push(it->to);
			}
		}
	}
	return eps;
}
