//
// Created by Cip on 5/18/2019.
//
#include <iostream>
#include "string"
#include "Tree.h"
Tree::Tree(string a)
{

    startingState=createNode(1);
    finalState=createNode(99999);
    cout<<"Reached this point in creating tree. Length of string "<<a<<" is "<<a.length()<<"\n";
    for(int i=0;i<a.length();i++)
        if(isalnum(a[i]))
            terminals.push_back(a[i]);

        a=startingState->deParanthesisIfier(a);
        startingState->connectInputToState(a,finalState);
    startingState->convert();



}
Node* Tree::createNode(int a)
{
    Node* lol=new Node(a);
    return lol;
}
