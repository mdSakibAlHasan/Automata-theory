#include<bits/stdc++.h>
#include<string.h>
using namespace std;

string grammer[] = {"E+E","E*E","(E)"};

int strlength(string str)
{
    int i=-1,counter=0;

    while(str[++i]){
        counter++;
    }

    return counter;
}




bool check(string a)
{
    for(int i=0;i<3;i++){
        if(grammer[i] == a){
            return true;
        }
    }

    return false;
}


int main()
{
   string str,temp;
    //getline(cin,str);
    cin>>str;

    //replace number by E
    for(int i=0;i<strlength(str);i++){
         if(str[i] == '0' || str[i] == '1'){
            str[i] = 'E';
         }
    }


    while(1){
        //make a temp array
        for(int k=0;k<strlength(str)-2;k++){
            int p =0;
            for(int i=k;i<k+3;i++){
                temp[p++] = str[k];
            }
            temp[p] = '\0';

            if(check(temp)){        //found match then replace
                str[k] = 'E';

                for(int x=k+3;x<strlength(str);x++){
                    str[++k] = str[x];
                }
                str[k] = '\0';
                break;
            }
        }



        if(str == "E"){
            cout<<"String accepted";
            break;
        }
        else if(strlength(str)<3){
            cout<<"String not accepted";
            break;
        }

    }


}
