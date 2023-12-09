#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
class hand{
    public:
    string s;
    int bid;
    int rank;
    int type;
};
int type_of_string(string s){
    //there are 7 categories
    // 1:all diff (high card),2:1 pair,3: 2pair,4: 3 of kind,5: full house(3 alike,2alike),6: four of kind,7: five of kind
    vector<int>freq(14);
    //we create a frequency array. A=1,T=10,J=11,Q=12,K=13;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A')freq[1]++;
        else if(s[i]=='T')freq[10]++;
        else if(s[i]=='J')freq[11]++;
        else if(s[i]=='Q')freq[12]++;
        else if(s[i]=='K')freq[13]++;
        else freq[s[i]-'0']++;
    }
    for(int i=1;i<=13;i++){
        if(freq[i]==5)return 7;
        else if(freq[i]==4)return 6;
        else if(freq[i]==3){
            for(int j=1;j<=13;j++){
                if(freq[j]==2)return 5; 
            }
            return 4;
        }
        else if(freq[i]==2){
            for(int j=1;j<=13;j++){
                if(freq[j]==3)return 5;
            }
            for(int j=1;j<=13;j++){
                if(j!=i && freq[j]==2)return 3;//caution!!!
                //j!=i lagaana bhool gye toh galti dhoondne pe bhi nhi milegi 
            }
            return 2;
        }
    }
    return 1;
}
int main(){
    vector<string>v;
    vector<int>bid;
    string s;
    cin>>s;
    int a;
    while(s.size()){
        cin>>a;
        v.push_back(s);
        bid.push_back(a);
        s.clear();
        cin>>s;
    }
    int n=v.size();
    vector<hand>ans(n);
    for(int i=0;i<n;i++){
        ans[i].s=v[i];
        ans[i].bid=bid[i];
    }
    for(int i=0;i<n;i++){
        ans[i].type=type_of_string(ans[i].s);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            if(ans[i].s[j]=='2')ans[i].s[j]='a';
            if(ans[i].s[j]=='3')ans[i].s[j]='b';
            if(ans[i].s[j]=='4')ans[i].s[j]='c';
            if(ans[i].s[j]=='5')ans[i].s[j]='d';
            if(ans[i].s[j]=='6')ans[i].s[j]='e';
            if(ans[i].s[j]=='7')ans[i].s[j]='f';
            if(ans[i].s[j]=='8')ans[i].s[j]='g';
            if(ans[i].s[j]=='9')ans[i].s[j]='h';
            if(ans[i].s[j]=='T')ans[i].s[j]='i';
            if(ans[i].s[j]=='J')ans[i].s[j]='j';
            if(ans[i].s[j]=='Q')ans[i].s[j]='k';
            if(ans[i].s[j]=='K')ans[i].s[j]='l';
            if(ans[i].s[j]=='A')ans[i].s[j]='m';
        }
    }
    sort(ans.begin(),ans.end(),[](const hand& lhs,const hand& rhs){return lhs.s<rhs.s;});
    for(int i=0;i<n;i++){
        ans[i].rank=1000*(ans[i].type)+i+1;
    }
    sort(ans.begin(),ans.end(),[](const hand& lhs,const hand& rhs){return lhs.rank<rhs.rank;});
    ll sum=0;
    for(int i=0;i<1000;i++){
       // cout<<ans[i].s<<" "<<ans[i].rank<<" "<<ans[i].bid<<endl;
        sum+=(ans[i].bid)*(i+1);
    }
    cout<<sum;
    return 0;
}
