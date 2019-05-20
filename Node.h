//
// Created by Cip on 5/18/2019.
//

#ifndef REGEXTODFA_NODE_H
#define REGEXTODFA_NODE_H
#include "string"
using namespace std;
class Node {
public:
    int value;
    bool isStartingState;
    bool isFinalState;
    Node* goToStates[50];
    string stateInputs[50];
    Node(int );
    void connectInputToState(string,Node*);
    string removeConnectionToState(string);
    Node* convertAsterisk();
    string deParanthesisIfier(string a);
};


#endif //REGEXTODFA_NODE_H
