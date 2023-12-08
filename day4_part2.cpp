#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>cards(192,1);
    int sum=0;
    for(int i=0;i<192;i++){
        char c;
        cin>>c;
        while(c!=':'){
            cin>>c;
        }
        vector<int>v1(10);
        for(int i=0;i<10;i++){
            cin>>v1[i];
        }
        cin>>c;
        vector<int>v2(25);
        for(int i=0;i<25;i++){
            cin>>v2[i];
        }
        int count=0;
        for(int i=0;i<25;i++){
            for(int j=0;j<10;j++){
                if(v2[i]==v1[j]){
                    count++;
                    break;
                }
            }
        }
        for(int j=i+1;j<i+1+count;j++){
            cards[j]+=cards[i];
        }
    }
    for(int i=0;i<192;i++){
        sum+=cards[i];
    }
    cout<<sum;
    return 0;
}
