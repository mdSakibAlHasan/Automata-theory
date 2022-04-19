#include<bits/stdc++.h>
using namespace std;
#define SIZE 100

int line;
char terminal[SIZE];
string grammer[SIZE][2],temp,str;
vector<char> table[SIZE][SIZE];
set<char> test;


void multiplicate(int i, int j, int p, int q)
{
    for(int x=0;x<table[i][j].size();x++){
        for(int y=0;y<table[p][q].size();y++){
            for(int k=0;k<line;k++){
                if(table[i][j][x] == grammer[k][1][0] &&  table[p][q][y] == grammer[k][1][1] ){

                    test.insert(grammer[k][0][0]);
                }
            }
        }
    }
}


void union_table(int i,int j)
{
    for(int k=i;k<j;k++){               //all posible combination
        multiplicate(i,k,k+1,j);
    }

    set<char>::iterator itr;
    for(itr=test.begin();itr!=test.end();itr++){        //set into table
        table[i][j].push_back(*itr);
    }
    test.clear();

}


void create_table()
{
    int i;
    for(int j=1;j<=str.size();j++){         //crate first line
        for(int k=0;k<line;k++){
            if(str[j-1] == terminal[k]){
                table[j][j].push_back(grammer[k][0][0]);
            }
        }
    }


    for(int x=2;x<=str.size();x++){
        i=1;
        for(int j=x;j<=str.size();j++){
                union_table(i,j);
                i++;
        }
    }



    cout<<"\n\n\nCYK table printed here: \n"<<endl;
    for(int x=str.size();x>0;x--){
        i=1;
        for(int j=x;j<=str.size();j++){
            for(int k=0;k<table[i][j].size();k++){
                cout<<table[i][j][k];
            }
            i++;
            cout<<"\t";
        }
        cout<<endl;
    }

    bool accepted = false;
    for(i=0;i<table[1][str.size()].size();i++){
        if(table[1][str.size()][i] == 'S'){
            accepted = true;
        }
    }

    if(accepted){
        cout<<"String Accepted"<<endl;
    }
    else{
        cout<<"String Not Accepted"<<endl;
    }

}


int main()
{
    freopen("in.txt","r",stdin);
    cout<<"Enter number of line: ";
    cin>>line;

    for(int i=0;i<line;i++){
        cin>>grammer[i][0]>>grammer[i][1]>>temp;

        if(temp[0] > 96 && temp[0] < 123){
            terminal[i] = temp[0];

        }
        else{
            i++;
            line++;
            grammer[i][0] = grammer[i-1][0];
            grammer[i][1] = temp;
            terminal[i-1] = '0';
            terminal[i] = '0';
        }


    }

    for(int i=0;i<line;i++){
        cout<<grammer[i][0]<<" two "<<grammer[i][1]<<" two "<<terminal[i]<<endl;
    }

    cout<<"Input string: ";
    cin>>str;

    create_table();

}
