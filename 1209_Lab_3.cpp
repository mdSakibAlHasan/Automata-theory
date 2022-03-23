#include<bits/stdc++.h>
using namespace std;

vector<string> state,symbol, table[20][20],line[20];
string start,final_state,phi = "phi";
set<string> sakib;
int trace=0;


void add_line(vector<string>test)
{
    if(test.size() == 0)
        return;
    //match with previous state

    for(int i=0;i<=trace;i++){
        if(line[i] == test){
            return;
        }
    }
    line[++trace] = test;
}

void add(set<string>sakib)
{
    set< string >::iterator itr;
    vector<string> test;

    cout<<"\t";
    for (itr = sakib.begin(); itr != sakib.end(); itr++) {
        
        test.push_back(*itr);
        if(itr == sakib.begin()){
            cout<<*itr;
        }
        else{
            cout<<","<<*itr;   
        }   
    }

    if(sakib.size() == 0){
        cout<<phi<<"\t";
    }
    else{
        add_line(test);
    } 
}

int find_index(string str)
{
    for(int i=0;i<state.size();i++){
        if(state[i] == str){
            return i;
        }
    }

    cout<<str<<"   input state does't match";
    exit(0);
}


bool isFinal(int index)
{
    for(int i=0;i<line[index].size();i++){
        if(line[index][i] == final_state){
            return true;
        }
    }

    return false;
}


void print_DFA(int number_of_state, int number_of_symbol)
{
    vector<string> temp;

    cout<<"State\t";
    for(int i=0;i<number_of_symbol;i++){
        cout<<symbol[i]<<"\t";
    }
    cout<<endl;

    if(state[0] == final_state){            //final state mark by star
        cout<<"*";
    }
    cout<<state[0]<<"\t";
    for(int i=0;i<number_of_symbol;i++){                //this segment use only for first row
        for(int k=0;k<table[0][i].size();k++){
            if((k+1) == table[0][i].size()){
                cout<<table[0][i][k]<<"\t";
            }
            else{
                cout<<table[0][i][k]<<",";
            }
            if(table[0][i][k] != phi){
                temp.push_back(table[0][i][k]);
            }  
        }

        sort(temp.begin(),temp.end());          //sort for matching
        add_line(temp);
        temp.clear();       //add again at first
    } 
    cout<<endl;

    
    int way =0;
    while(++way <= trace){
        if(isFinal(way)){           //this state uis final we mark it by star
            cout<<"*";
        }

        for(int i=0;i<line[way].size();i++){        
            if((i+1) == line[way].size()){
                cout<<line[way][i];
            }
            else{
                cout<<line[way][i]<<",";
            }
        }

        //insert into set
        for(int j=0;j<number_of_symbol;j++){
            for(int i=0;i<line[way].size();i++){
                //find and match
                int index = find_index(line[way][i]);
                for(int k=0;k<table[index][j].size();k++){
                    if(table[index][j][k] != phi){
                        sakib.insert(table[index][j][k]);
                    }    
                }
            }
            add(sakib);
            sakib.clear();

            //print list
            
        }
        cout<<endl;

    }
}



void fill_up_table(int index, string str)
{
    char store[20];
    int i=-1,j=0,p=0;

    while(str[++i]){
        if(str[i] == 32){                   //space used for different state
            store[j] = '\0';
            table[index][p++].push_back(store);
            j =0;
        }
        else if(str[i] == 44){          //comma use for same state
            store[j] = '\0';
            table[index][p].push_back(store);
            j =0;
        }
        else{
            store[j++] = str[i];
        }
    }

    store[j] = '\0';                        //for last value it out from loop
    table[index][p++].push_back(store);

}


void input_table(int number_of_state, int number_of_symbol)
{
    cout<<"\n Input table: \n";
    cout<<"State ";
    for(int i=0;i<number_of_symbol;i++){
        cout<<symbol[i]<<"\t";
    }
    cout<<endl;

    string str;
    getchar();
    for(int i=0;i<number_of_state;i++){
        if(state[i] == final_state)
            cout<<"*";
        cout<<state[i]<<"\t";

        getline(cin,str);
        fill_up_table(i,str);
    }

    print_DFA(number_of_state, number_of_symbol);
}


void input()
{
    int number_of_state, number_of_symbol;
    string temp;

    cout<<"State number: ";
    cin>>number_of_state;

    for(int i=0;i<number_of_state;i++){
        cin>>temp;
        state.push_back(temp);
    }

    cout<<"Number of symbol: ";
    cin>>number_of_symbol;

    for(int i=0;i<number_of_symbol;i++){
        cin>>temp;
        symbol.push_back(temp);
    }

    cout<<"Starting state: ";
    cin>>start;
    line[0].push_back(start);

    cout<<"Final state: ";
    cin>>final_state;

    input_table(number_of_state,number_of_symbol);          //input NFA table

}

int main()
{
    //freopen("in","r+",stdin);
    input();
}