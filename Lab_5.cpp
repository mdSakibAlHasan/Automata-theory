#include<bits/stdc++.h>
using namespace std;

char stk[100],top=0;
bool accepted = false;
string str;
int SIZE;

void printStack()
{
    for(int i=0;i<top;i++)
    {
        cout<<i<<"***";
        cout<<stk[i];
    }
    cout<<"Z";
}


void printState(int temp)
{
    for(int i=0;i<temp;i++)
    {
        cout<<i<<temp<<"***";
        cout<<"q0,"<<str[i]<<", ";
        printStack();

        str[top++] = str[i];
        cout<<" ->  q0,";
        printStack();
        cout<<endl;
        if(i>30)
           break;
    }

    cout<<" String arte "<<str<<endl;
    for(int i=temp;i<str.size();i++)
    {
        cout<<i<<str.size()<<"***";
        if(i == temp){
            cout<<"q0,"<<str[i]<<", ";
        }
        else{
            cout<<"q1,"<<str[i]<<", ";
        }
        printStack();

        top--;              //pop element
        cout<<" ->  q1,";
        printStack();
        cout<<endl;

        if(i>30)
           break;
    }

}

void search()
{
    int i,j,temp;
    for(i=0;i<str.size();i++){
        top = -1;
        for(j=0;j<i;j++){
            stk[++top] = str[i];
        }
        temp = j;
        for( ;j<str.size();j++){
            if(str[top--] != str[j]){
                break;
            }
        }

        if(top == -1 && j == str.size()){
            //printState(temp);
            accepted = true;
            break;
        }
    }

    if(accepted){
        cout<<"String accepted\n";
    }
    else{
        cout<<"String not accepted";
    }
}


int main()
{
    cout<<"Input string ";
    cin>>str;
    SIZE = str.size();

    search();
}