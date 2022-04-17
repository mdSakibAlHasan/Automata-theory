#include<bits/stdc++.h>
using namespace std;
#define SIZE 100

int line;
char terminal[SIZE];
string grammer[SIZE][2],temp,str;
vector<char> table[SIZE][SIZE];
set<char> test;


void multiplicate(int i, int j, int p, int q,int table_index)
{
    for(int x=0;x<table[i][j].size();x++){
        for(int y=0;y<table[p][q].size();y++){
            for(int k=0;k<line;k++){
                if(table[i][j][x] == grammer[k][1][0] &&  table[i][j][y] == grammer[k][1][1] ){
                    cout<<grammer[k][0][0]<<"\t"<<endl;
                    test.insert(grammer[k][0][0]);
                }
            }
        }
    }
}


void union_table(int i,int j, int table_index)
{
    test.clear();
    for(int k=i;k<j;k++){
        multiplicate(i,k,k+1,j, table_index);
    }

    set<char>::iterator itr;

    for(itr=test.begin();itr!=test.end();itr++){
        table[table_index][i].push_back(*itr);
    }

}


void create_table()
{
    int i;

    for(int x=1;x<=str.size();x++){
        i=1;
        for(int j=x;j<=str.size();j++){

            if(x == 1){
                for(int k=0;k<line;k++){
                    if(str[i-1] == terminal[k]){
                        table[x][i].push_back(grammer[k][0][0]);
                    }
                }
                //cout<<"\t";

            }
            else{
                union_table(i,j,x);
            }

            i++;
        }
    //cout<<endl;
    }



    cout<<"\n\n\n";
    for(int p=5;p>=0;p--){
    for(int i=1;i<= str.size();i++){
        for(int j=0;j<table[1][i].size();j++){
            cout<<table[p][i][j];
        }
        cout<<"\t";
    }
    cout<<endl;
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

        //cout<<grammer[i][0]<<" two "<<grammer[i][1]<<" two "<<terminal[i]<<endl;

    }

    for(int i=0;i<line;i++){
        cout<<grammer[i][0]<<" two "<<grammer[i][1]<<" two "<<terminal[i]<<endl;
    }

    cout<<"Input string: ";
    cin>>str;

    create_table();



}
