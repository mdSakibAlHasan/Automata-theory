#include<bits/stdc++.h>
using namespace std;

const int SIZE = 100;

vector<string> state_name,input_symbol,final_state;
string str,starting_state;
int table[SIZE][SIZE];


int find_index(vector<string> test, string str)
{
    for(int i=0;i<test.size();i++){
        if(test[i] == str){
            return i;
        }
    }
    return -1;
}


vector<string> separate_symbol(string str, vector<string>test)
{
    int i=0,j=0;
    char temp[SIZE];

    while(str[i]){
        if(str[i] == 32){
            temp[j] = '\0';
            //cout<<temp<<" pre ";
            test.push_back(temp);
            j=0;
        }
        else{
            temp[j++] = str[i];
        }
        i++;
    }

    temp[j] = '\0';
    test.push_back(temp);

    //cout<<test.size()<<" size ";

    return test;
}


void input()
{
    vector<string> sakib;

    int state;

    cout<<"Input state name separated by space: ";
    getline(cin,str);
    state_name = separate_symbol(str,state_name);

    cout<<"Input symbol separated by space: ";
    getline(cin,str);
    input_symbol = separate_symbol(str,input_symbol);

    cout<<"Starting state: ";
    cin>>starting_state;
    getchar();

    cout<<"Input final state name separated by space: ";
    getline(cin,str);
    final_state = separate_symbol(str,final_state);


    cout<<"State_name\t";
    for(int i=0;i<input_symbol.size();i++){
        cout<<input_symbol[i]<<"\t";
    }
    cout<<endl;

    for(int i=0;i<state_name.size();i++){
        if(find_index(final_state, state_name[i]) !=-1){
                cout<<"*";
            }
        cout<<state_name[i]<<"\t";

        getline(cin,str);
        sakib = separate_symbol(str,sakib);

        for(int j=0;j<input_symbol.size();j++){
            state = find_index(state_name,sakib[j]);
            if(state != -1){
                table[i][j] = state;
            }
            else{
                cout<<"state does not match ";
                exit(1);
            }
        }
        sakib.clear();
    }

    /*for(int i=0;i<state_name.size();i++){
        for(int j=0;j<input_symbol.size();j++){
            cout<<table[i][j]<<"\t";
        }
        cout<<endl;
    }*/
}

int check_symbol(char ch)
{
    for(int i=0;i<input_symbol.size();i++){
        if(ch == input_symbol[i][0])
            return i;
    }
    cout<<"Wrong input";
    exit(1);
}


void check_state()
{
    string str;
    cout<<"Input string: ";
    cin>>str;

    int i=0,k,state_number = 0;
    cout<<starting_state;
    while(str[i]){
        k = check_symbol(str[i]);
        state_number = table[state_number][k];
        cout<<" - ("<<str[i++]<<") "<<state_name[state_number];
    }

    if(find_index(final_state, state_name[state_number]) != 0){
        cout<<"\n Accepted";
    }
    else{
        cout<<"\n Not accepted";
    }

}


int main()
{
     //freopen("in.txt","r",stdin);
    input();

    check_state();
}
