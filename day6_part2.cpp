#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    vector<int>time={53,71,78 ,80};
    vector<int>dist={275,1181,1215,1524};
    //lets say for x seconds button is pressed
    //(t-x)x>=d  => Leastinteger[(t-sqrt(t^2-4d))/2] <=x<= GIF[(t+sqrt(t^2-4d))/2] 
    vector<int>count(4);
    string times,distance;
    for(int i=0;i<4;i++){
        times+=to_string(time[i]);
        distance+=to_string(dist[i]);
    }
    ll t=stoll(times);
    ll d=stoll(distance);
    ll a=ceil((t-sqrt(t*t-4*d))/2);//sqrt is float,so thing inside ceil is also float
    ll b=floor((t+sqrt(t*t-4*d))/2);
    cout<<b-a+1;
    return 0;
}
