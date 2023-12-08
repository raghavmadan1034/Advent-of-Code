#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int count=0;
    while(s.size()){
        int temp,index1,id;
        int b=0,g=0,r=0;
        int bmin=0,gmin=0,rmin=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==':'){
                index1=i+1;
                break;
            }
        }
        if(isdigit(s[6])){
            id=10*(s[5]-'0')+s[6]-'0';
        }
        else{
            id=s[5]-'0';
        }
        int flag=1;
        for(int i=index1;i<s.size();i++){
            if(s[i]==';' || i==s.size()-1){
                if(r>rmin)rmin=r;
                if(g>gmin)gmin=g;
                if(b>bmin)bmin=b;
                b=0;
                g=0;
                r=0;
                continue;
            }
            //if(flag==0)break;
            if(isdigit(s[i])){
                if(isdigit(s[i+1])){
                    if(s[i+3]=='b')b=10*(s[i]-'0')+s[i+1]-'0';
                    if(s[i+3]=='r')r=10*(s[i]-'0')+s[i+1]-'0';
                    if(s[i+3]=='g')g=10*(s[i]-'0')+s[i+1]-'0'; 
                    i+=2;
                
                }
                else{
                    if(s[i+2]=='b')b=(s[i]-'0');
                    if(s[i+2]=='r')r=(s[i]-'0');
                    if(s[i+2]=='g')g=(s[i]-'0');
                    i++;
                }
            }

        }
        //cout<<bmin<<" "<<rmin<<" "<<gmin<<endl;
        count+=bmin*rmin*gmin;

        s.clear();
        getline(cin,s);
    }
    cout<<count;
    return 0;
}
