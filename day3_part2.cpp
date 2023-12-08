#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<char>>v(140,vector<char>(140));
    for(long long i=0;i<140;i++){
        for(long long j=0;j<140;j++){
            cin>>v[i][j];
        }
    }
    long long sum=0;
    //cout<<v.size();
    int count1=0;
    for(long long i=0;i<v.size();i++){
        for(long long j=0;j<v.size();j++){
            if(v[i][j]=='*'){
                count1++;
                long long product=1;
                long long count=0;
                if(i-1>=0 && isdigit(v[i-1][j])){//up
                    long long jtemp2=j;
                    while(jtemp2>=0 && isdigit(v[i-1][jtemp2])){
                        jtemp2--;
                    }
                    long long jtemp=jtemp2+1;
                    long long number=0;
                    while(isdigit(v[i-1][jtemp])){
                        number*=10;
                        number+=v[i-1][jtemp]-'0';
                        v[i-1][jtemp]='.';
                        jtemp++;
                    }
                    product*=number;
                    count++;
                }
                if(j-1>=0 && isdigit(v[i][j-1])){//left
                    long long jtemp2=j-1;
                    while(jtemp2>=0 && isdigit(v[i][jtemp2])){
                        jtemp2--;
                    }
                    long long jtemp=jtemp2+1;
                    long long number=0;
                    while(isdigit(v[i][jtemp])){
                        number*=10;
                        number+=v[i][jtemp]-'0';
                        v[i][jtemp]='.';
                        jtemp++;
                    }
                    product*=number;
                    count++;
                }
                if(i+1<v.size() && isdigit(v[i+1][j])){//down
                    long long jtemp2=j;
                    while(jtemp2>=0 && isdigit(v[i+1][jtemp2])){
                        jtemp2--;
                    }
                    long long jtemp=jtemp2+1;
                    long long number=0;
                    while(isdigit(v[i+1][jtemp])){
                        number*=10;
                        number+=v[i+1][jtemp]-'0';
                        v[i+1][jtemp]='.';
                        jtemp++;
                    }
                    product*=number;
                    count++;
                }
                if(j+1<v.size() && isdigit(v[i][j+1])){//right
                    long long jtemp=j+1;
                    long long number=0;
                    while(isdigit(v[i][jtemp])){
                        number*=10;
                        number+=v[i][jtemp]-'0';
                        v[i][jtemp]='.';
                        jtemp++;
                    }
                    product*=number;
                    count++;
                }
                if(i-1>=0 && j-1>=0 && isdigit(v[i-1][j-1])){//upleft diagonal
                    long long jtemp2=j-1;
                    while(jtemp2>=0 && isdigit(v[i-1][jtemp2])){
                        jtemp2--;
                    }
                    long long jtemp=jtemp2+1;
                    long long number=0;
                    while(isdigit(v[i-1][jtemp])){
                        number*=10;
                        number+=v[i-1][jtemp]-'0';
                        v[i-1][jtemp]='.';
                        jtemp++;
                    }
                    product*=number;
                    count++;
                }
                if(i-1>=0 && j+1<v.size() && isdigit(v[i-1][j+1])){//upright diagonal
                    long long jtemp2=j+1;
                    while(jtemp2>=0 && isdigit(v[i-1][jtemp2])){
                        jtemp2--;
                    }
                    long long jtemp=jtemp2+1;
                    long long number=0;
                    while(isdigit(v[i-1][jtemp])){
                        number*=10;
                        number+=v[i-1][jtemp]-'0';
                        v[i-1][jtemp]='.';
                        jtemp++;
                    }
                    product*=number;
                    count++;
                }
                if(i+1<v.size() && j+1<v.size() && isdigit(v[i+1][j+1])){//downright diagonal
                    long long jtemp2=j+1;
                    while(jtemp2>=0 && isdigit(v[i+1][jtemp2])){
                        jtemp2--;
                    }
                    long long jtemp=jtemp2+1;
                    long long number=0;
                    while(isdigit(v[i+1][jtemp])){
                        number*=10;
                        number+=v[i+1][jtemp]-'0';
                        v[i+1][jtemp]='.';
                        jtemp++;
                    }
                    product*=number;
                    count++;
                }
                if(i+1<v.size() && j-1>=0 && isdigit(v[i+1][j-1])){//downleft diagonal
                    long long jtemp2=j-1;
                    while(jtemp2>=0 && isdigit(v[i+1][jtemp2])){
                        jtemp2--;
                    }
                    long long jtemp=jtemp2+1;
                    long long number=0;
                    while(isdigit(v[i+1][jtemp])){
                        number*=10;
                        number+=v[i+1][jtemp]-'0';
                        v[i+1][jtemp]='.';
                        jtemp++;
                    }
                    product*=number;
                    count++;
                }
                if(count==2)sum+=product;

            }
        }
    }
    cout<<sum;
    return 0;
}
