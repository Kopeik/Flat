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

    Node* goToStates[50];
    string stateInputs[50];
    Node(int );
    void connectInputToState(string,Node*);
    string removeConnectionToState(string);
    string deParanthesisIfier(string);
    void convert();
    int levelSlashSearch(string);
    int concatenationSearch(string);
};


#endif //REGEXTODFA_NODE_H
