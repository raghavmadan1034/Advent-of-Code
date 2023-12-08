#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int count=0;
    while(s.size()){
        int temp,index1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='o' && s[i+1]=='n' && s[i+2]=='e'){
                temp=10;
                break;
            }
            if(s[i]=='t' && s[i+1]=='w' && s[i+2]=='o'){
                temp=20;
                break;
            }
            if(s[i]=='t' && s[i+1]=='h' && s[i+2]=='r' && s[i+3]=='e' && s[i+4]=='e'){
                temp=30;
                break;
            }
            if(s[i]=='f' && s[i+1]=='o' && s[i+2]=='u' && s[i+3]=='r'){
                temp=40;
                break;
            }
            if(s[i]=='f' && s[i+1]=='i' && s[i+2]=='v' && s[i+3]=='e'){
                temp=50;
                break;
            }
            if(s[i]=='s' && s[i+1]=='i' && s[i+2]=='x'){
                temp=60;
                break;
            }
            if(s[i]=='s' && s[i+1]=='e' && s[i+2]=='v' && s[i+3]=='e' && s[i+4]=='n'){
                temp=70;
                break;
            }
            if(s[i]=='e' && s[i+1]=='i' && s[i+2]=='g' && s[i+3]=='h' && s[i+4]=='t'){
                temp=80;
                break;
            }
            if(s[i]=='n' && s[i+1]=='i' && s[i+2]=='n' && s[i+3]=='e'){
                temp=90;
                break;
            }
            if(isdigit(s[i])){
                temp=10*(s[i]-'0');
                break;
            }
        }
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='o' && s[i+1]=='n' && s[i+2]=='e'){
                temp+=1;
                break;
            }
            if(s[i]=='t' && s[i+1]=='w' && s[i+2]=='o'){
                temp+=2;
                break;
            }
            if(s[i]=='t' && s[i+1]=='h' && s[i+2]=='r' && s[i+3]=='e' && s[i+4]=='e'){
                temp+=3;
                break;
            }
            if(s[i]=='f' && s[i+1]=='o' && s[i+2]=='u' && s[i+3]=='r'){
                temp+=4;
                break;
            }
            if(s[i]=='f' && s[i+1]=='i' && s[i+2]=='v' && s[i+3]=='e'){
                temp+=5;
                break;
            }
            if(s[i]=='s' && s[i+1]=='i' && s[i+2]=='x'){
                temp+=6;
                break;
            }
            if(s[i]=='s' && s[i+1]=='e' && s[i+2]=='v' && s[i+3]=='e' && s[i+4]=='n'){
                temp+=7;
                break;
            }
            if(s[i]=='e' && s[i+1]=='i' && s[i+2]=='g' && s[i+3]=='h' && s[i+4]=='t'){
                temp+=8;
                break;
            }
            if(s[i]=='n' && s[i+1]=='i' && s[i+2]=='n' && s[i+3]=='e'){
                temp+=9;
                break;
            }
            if(isdigit(s[i])){
                temp+=s[i]-'0';
                break;
            }
        }
        count+=temp;
        s.clear();
        getline(cin,s);
    }
    cout<<count;
    return 0;
}
