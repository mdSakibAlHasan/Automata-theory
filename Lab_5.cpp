#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define SIZE 100

char stk[100];
int top;
bool accepted = false,first = true;

void print_stack()
{
    for(int i=0;i<top;i++){
        cout<<stk[i];
    }
    cout<<"Z";
}


void control_stack(char str[], int temp)
{
    top = 0;
    for(int i=0;i<temp;i++){
        cout<<"q0,push-"<<str[i]<<",";
        print_stack();

        stk[top++] = str[i];
        cout<<" -> q0,";
        print_stack();
        cout<<endl;
    }

    while(top){
         if(first){
            cout<<"q0, pop-"<<stk[--top]<<" -> ";
            first = false;
         }
         else{
            cout<<"q1, pop-"<<stk[--top]<<" -> ";
         }
        cout<<"q1,";
        print_stack();
        cout<<endl;
    }

    cout<<"q1, eps -> q2, Z"<<endl;
}


void search(char str[])
{
    int i,j,temp;
    for(i=0;i<strlen(str);i++){
        top = -1;
        for(j=0;j<i;j++){
            stk[++top] = str[i];
        }
        temp = j;
        for( ;j<strlen(str);j++){
            if(str[top--] != str[j]){
                break;
            }
        }

        if(top == -1 && j == strlen(str)){
            accepted = true;
            control_stack(str,temp);
            break;
        }
    }

    if(accepted){
        cout<<"\nString accepted\n";
    }
    else{
        cout<<"\nString not accepted";
    }
}


int main()
{
    char str[SIZE];
    cout<<"Input string ";
    cin>>str;

    search(str);
}
