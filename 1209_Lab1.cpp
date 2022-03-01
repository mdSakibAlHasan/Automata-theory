#include<bits/stdc++.h>
using namespace std;

#define SIZE 200
bool isFinal;

void third(char str[], int index);
void second(char str[], int index);


void first(char str[], int index)
{
    isFinal = false;

    if(str[index]){
        if(str[index] == '0'){
            cout<<"- (0) -> Q0";
            first(str, ++index);
        }
        else{
            cout<<"- (1) -> Q1";
            second(str, ++index);
        }
    }
}

void second(char str[], int index)
{
    isFinal = false;

    if(str[index]){
        if(str[index] == '0'){
            cout<<"- (0) -> Q0";
            first(str, ++index);
        }
        else{
            cout<<"- (1) -> Q2";
            third(str, ++index);
        }
    }
}

void third(char str[], int index)
{
    isFinal = true;

    if(str[index]){
        if(str[index] == '0'){
            cout<<"- (0) -> Q0";
            first(str, ++index);
        }
        else{
            cout<<"- (1) -> Q2";
            third(str, ++index);
        }
    }
}

int main()
{
    char str[SIZE], temp;

    cout<<"Input string: ";
    cin>>str;

    cout<<"Start -> Q0";
    first(str, 0);

    if(isFinal){
        cout<<"\n Accepted";
    }
    else{
        cout<<"\n Not accepted";
    }
}
