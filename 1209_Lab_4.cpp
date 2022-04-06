#include<bits/stdc++.h>
using namespace std;

int size;
string grammer[] = {"E+E","E*E","(E)"};

int strlength(string str)
{
    int i=-1,counter=0;

    while(str[++i]){
        counter++;
    }

    return counter;
}




bool check(string a, int k)
{
    for(int j=0;j<3;j++){
        if((grammer[j][0] == a[k])  &&  (grammer[j][1] == a[k+1])  &&  (grammer[j][2] == a[k+2]))
            return true;
    }
    return false;
}



int main()
{
    string str,temp;
    cout<<"Input string: ";
    cin>>str;
    size = str.size();

    //replace two data by 1
    for(int i=0;i<strlength(str);i++){
        if(str[i] == '0' || str[i] == '1'){
            str[i] = 'E';
        }
    }

    
    int counter=0;
    while(counter++<20){
        
        for(int k=0;k<str.size()-2;k++){
    
            if(check(str,k)){        //found match then replace
                str[k] = 'E';
                for(int x=k+3;x<=str.size();x++){
                    str[++k] = str[x];
                }
                str[++k] = '\0';
                break;
            }
        }

        if(strlength(str) == 1){
            cout<<"String accepted";
            break;
        }
        else if(strlength(str)<3){
            cout<<"String not accepted";
            break;
        }
    }
	
    if(counter == 21){
	cout<<"string not acceopted"<<endl;
     }

}
