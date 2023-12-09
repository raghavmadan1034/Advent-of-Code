#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>time={53,71,78 ,80};
    vector<int>dist={275,1181,1215,1524};
    //lets say for x seconds button is pressed
    //(t-x)x>=d  => Leastinteger[(t-sqrt(t^2-4d))/2] <=x<= GIF[(t+sqrt(t^2-4d))/2] 
    vector<int>count(4);
    int product=1;
    for(int i=0;i<4;i++){
        int a=ceil((time[i]-sqrt(time[i]*time[i]-4*dist[i]))/2);//sqrt is float,so thing inside ceil is also float
        int b=floor((time[i]+sqrt(time[i]*time[i]-4*dist[i]))/2);
        count[i]=b-a+1;
        product*=count[i];
    }
    cout<<product;
    return 0;
}
