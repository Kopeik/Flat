//
// Created by Cip on 5/18/2019.
//

#include <iostream>
#include "Node.h"
#include <string.h>
#include <string>
Node::Node(int a)
{
    value=a;

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
    while (ok==false)
    {
        ok=true;
        for(int i=0;stateInputs[i]!="";i++)
        {
            if(stateInputs[i].length()>1) {
                ok = false;
                int splitter = levelSlashSearch(stateInputs[i]);

                if (splitter != -1) {
                    if (splitter == 0) {
                        cout << "Something went wrong. Splitting at very beginning in: " << stateInputs[i];
                        throw RegexIncorrect();
                    } else {

                        string left = stateInputs[i].substr(0, splitter);
                        string right = stateInputs[i].substr(splitter + 1, stateInputs[i].length() - splitter);
                        cout << "Splitted " << stateInputs[i] << " into " << left << " and " << right << endl;
                        stateInputs[i] = deParanthesisIfier(left);
                        connectInputToState(deParanthesisIfier(right), goToStates[i]);
                    }
                } else {
                    int splitconc = concatenationSearch(stateInputs[i]);
                    if (splitconc != -1) {
                        string left = stateInputs[i].substr(0, splitconc + 1);
                        string right = stateInputs[i].substr(splitconc + 1, stateInputs[i].length() - splitconc);
                        cout << "Splitted " << stateInputs[i] << " into " << left << " and " << right << endl;
                        Node *ne = new Node(value + 1);
                        ne->connectInputToState(deParanthesisIfier(right), goToStates[i]);
                        removeConnectionToState(stateInputs[i]);
                        connectInputToState(deParanthesisIfier(left), ne);
                    }
                    else
                    {
                        if(stateInputs[i][stateInputs[i].length()-1]=='*')
                        {
                            string toCon=deParanthesisIfier(   stateInputs[i].substr(0,stateInputs[i].length()-1));
                            connectInputToState(toCon,this);
                            connectInputToState(toCon,goToStates[i]);
                            removeConnectionToState(stateInputs[i]);

                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<50;i++)
    {
        if(goToStates[i]!= nullptr)
        goToStates[i]->convert();
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
int Node::concatenationSearch(string a) {
    int i=0;
    int open=0;

    if(a[0]==')' or a[0]=='/' or a[0]=='*' )
        throw RegexIncorrect();
    while(i<a.length()-1)
    {
        if(a[i]=='(')
            open++;
        if(a[i]==')')
            open--;
        if(isalnum(a[i])or a[i]==')')
            if(open==0)
                if(isalnum(a[i+1]) or a[i+1]=='(')
                    return i;
        i++;
    }
    return -1;
}
