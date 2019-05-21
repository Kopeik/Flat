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
    string deParanthesisIfier(string);
    void convert();
    int levelSlashSearch(string);
    void slash_convertInput(int index,int slIndex);
};


#endif //REGEXTODFA_NODE_H
