//
// Created by Cip on 5/18/2019.
//

#ifndef REGEXTODFA_TREE_H
#define REGEXTODFA_TREE_H
#include "Node.h"

class Tree {
public:

    Node* startingState;
    Node* finalState;
    string terminals;
    Tree(string);
    Node* createNode(int);


};


#endif //REGEXTODFA_TREE_H
