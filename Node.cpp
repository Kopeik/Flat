//
// Created by Cip on 5/18/2019.
//

#include <iostream>
#include "Node.h"
Node::Node(int a)
{
    value=a;
    isStartingState= false;
    isFinalState=false;
    for(int i=0;i<50;i++)
    {
        goToStates[i]= nullptr;
    }
}
exception RegexIncorrect()
{
    cout<<"Sorry!The regex you inputed was incorrect.";
}
string Node::removeConnectionToState(string a) {
    bool ok=false;
for(int i=0;goToStates[i]!= nullptr;i++)
{
    if(a==stateInputs[i])
    {
        cout<<"DELETING connection ["<<a<<"] with state ("<<goToStates[i]->value<<")\n";
        ok=true;
        for(int j=i;goToStates[j]!= nullptr;j++)
        {
            goToStates[j]=goToStates[j+1];
            stateInputs[j]=stateInputs[j+1];
        }
    }
}
if(ok== false)
    cout<<"Couldn't delete the connection ["<<a<<"] at state ("<<value<<"). Connection not existent\n";
return a;
}
void Node::connectInputToState(string a,Node* theNode)
{
    cout<<"Creating connection ["<<a<<"] with state ("<<theNode->value<<")\n";
    int i;
    for(i=0; goToStates[i]!= nullptr;i++);
    goToStates[i]=theNode;
    stateInputs[i]=a;
}
string Node::deParanthesisIfier(string a) {
    bool ok=false;
   while(a[0]=='('&&a[a.length()-1]==')')
    {
        a.erase(0,1);
        a.erase(a.length()-1,1);
        cout<<"Deparenthesisified the string "<<a<<endl;
        ok=true;
    }
   if(ok== false)
   {
       cout<<"Didn't need to deparenthesisify string "<<a<<endl;
   }
   return a;
}

void Node::convert() {
    bool ok=false;
    int i=0;
    while (ok==false)
    {
        ok=true;
        if(stateInputs[i].length()>1) {
            ok = false;
            int splitter=levelSlashSearch(stateInputs[i]);
            if(splitter==0)
            {
                cout<<"Something went wrong. Splitting at very beginning in: "<<stateInputs[i];
                throw RegexIncorrect();

            }
            if(splitter!=-1)
            {

            }


        }

    }


}

int Node::levelSlashSearch(string a) {
    int i=0;
    int open=0;

    if(a[0]==')' or a[0]=='/' or a[0]=='*' )
        throw RegexIncorrect();
    while(i<a.length())
    {
        if(a[i]=='(')
            open++;
        if(a[i]==')')
            open--;
        if(a[i]=='/')
            if(open==0)
                return i;
            i++;
    }
    return -1;

}

void Node::slash_convertInput(int index, int slIndex) {



}
