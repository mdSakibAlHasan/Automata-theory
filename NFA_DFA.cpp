#include<bits/stdc++.h>
using namespace std;

char table[100][2],state[100];
char store[10][10];
int track=0;


void print_state(char ch[])
{
    int n = strlen(ch);
    cout<<"{ ";
    for(int i=0;i<n;i++){
        if(i+1 != n){
             cout<<ch[i]<<", ";
        }
        else{
             cout<<ch[i]<<" }";
        }
       
    }
}


int find_state(char ch,int s)
{
    for(int i=0;i<s;i++){
        if(ch == state[i]){
            return i;
        }
    }

    exit(-1);
}


void add(char ch, int index)
{
    int x = strlen(store[index]);
    store[index][x] = ch;
    store[index][++x] = '\0';
}


void make_DFA(int state_number,char start_state, char final_state)
{
    cout<<"State\t 0 \t   1\n";
    int i=0;
    store[i][0] = start_state;
    store[i][1] = '\0';
    track++;
    while(i<state_number){
        print_state(store[i]);

        for(int j=0;j<strlen(store[i]);j++){
            char ch = table[find_state(store[i][j], state_number)][0];
            if(store[i][j] == ch){
                add(ch,i+1)
            }

            
        }
    }
}


int main()
{
    int state_number, language_number;
    char  language[100], start_state, final_state;

    cout<<"Input number of state: ";
    cin>>state_number;

    for(int i=0;i<state_number;i++){
        cin>>state[i];
    }

    cout<<"Starting state: ";
    cin>>start_state;

    cout<<"Input final state: ";
    cin>>final_state;

    //input transition table

    cout<<"Input transition table\n";
    cout<<"State  0     1\n";
    for(int i=0;i<state_number;i++){
        cout<<state[i]<<"   ";
        cin>>table[i][0]>>table[i][1];
    }

}             