#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isnumber(string s){
    for(int i=0;i<s.size();i++){
        if(!isdigit(s[i]))return false;
    }
    return true;
}
void input(vector<string>&v,vector<vector<ll>>&seed_to_soil,vector<vector<ll>>&soil_to_fertilizer,vector<vector<ll>>&fertilizer_to_water,vector<vector<ll>>&water_to_light,vector<vector<ll>>&light_to_temperature,vector<vector<ll>>&temperature_to_humidity,vector<vector<ll>>&humidity_to_location){
    int i=0;
    i++;
    while(isnumber(v[i])){
        ll a=stoll(v[i]);
        ll b=stoll(v[i+1]);
        ll c=stoll(v[i+2]);
        seed_to_soil.push_back({a,b,c});
        i+=3;
    }
    i++;
    while(isnumber(v[i])){
        ll a=stoll(v[i]);
        ll b=stoll(v[i+1]);
        ll c=stoll(v[i+2]);
        soil_to_fertilizer.push_back({a,b,c});
        i+=3;
    }
    i++;
    while(isnumber(v[i])){
        ll a=stoll(v[i]);
        ll b=stoll(v[i+1]);
        ll c=stoll(v[i+2]);
        fertilizer_to_water.push_back({a,b,c});
        i+=3;
    }
    i++;
    while(isnumber(v[i])){
        ll a=stoll(v[i]);
        ll b=stoll(v[i+1]);
        ll c=stoll(v[i+2]);
        water_to_light.push_back({a,b,c});
        i+=3;
    }
    i++;
    while(isnumber(v[i])){
        ll a=stoll(v[i]);
        ll b=stoll(v[i+1]);
        ll c=stoll(v[i+2]);
        light_to_temperature.push_back({a,b,c});
        i+=3;
    }
    i++;
    while(isnumber(v[i])){
        ll a=stoll(v[i]);
        ll b=stoll(v[i+1]);
        ll c=stoll(v[i+2]);
        temperature_to_humidity.push_back({a,b,c});
        i+=3;
    }
    i++;
    while(i+2<v.size() && isnumber(v[i])){
        ll a=stoll(v[i]);
        ll b=stoll(v[i+1]);
        ll c=stoll(v[i+2]);
        humidity_to_location.push_back({a,b,c});
        i+=3;
    }
}
int main(){
    //-------------Taking the input--------------------------------------------- 
    vector<ll>seed_previous={2149186375, 163827995, 1217693442, 67424215, 365381741, 74637275, 1627905362,77016740, 22956580, 60539394 ,586585112, 391263016, 2740196667, 355728559, 2326609724, 132259842, 2479354214, 184627854, 3683286274, 337630529};
    //NOTE- Before taking the input delete the string "map:" from the input
    //eg -"seed-to-soil map:" deleting "map:" makes it "seed-to-soil"
    vector<string>v;
    string s;
    getline(cin,s);
    while(s.size()){
        v.push_back(s);
        s.clear();
        cin>>s;
    }
    vector<vector<ll>>seed_to_soil;
    vector<vector<ll>>soil_to_fertilizer;
    vector<vector<ll>>fertilizer_to_water;
    vector<vector<ll>>water_to_light;
    vector<vector<ll>>light_to_temperature;
    vector<vector<ll>>temperature_to_humidity;
    vector<vector<ll>>humidity_to_location;
    input(v,seed_to_soil,soil_to_fertilizer,fertilizer_to_water,water_to_light,light_to_temperature,temperature_to_humidity,humidity_to_location);
    //------------------------------Taking the input ends-----------------------------
    vector<ll>seed;
    for(int i=0;i<20;i+=2){
        seed.push_back(seed_previous[i]);
    }
    vector<ll>range;
    for(int i=1;i<20;i+=2){
        range.push_back(seed_previous[i]);
    }
    int n=seed.size();
    vector<ll>minimum(n,LLONG_MAX);
    vector<ll>soil(n,-1);
    vector<ll>fertilizer(n,-1);
    vector<ll>water(n,-1);
    vector<ll>light(n,-1);
    vector<ll>temperature(n,-1);
    vector<ll>humidity(n,-1);
    vector<ll>location(n,-1);
    for(int i=0;i<n;i++){
        ll a=seed[i];
        for(ll k=0;k<range[i];k++){
            seed[i]=a+k;
            for(int j=0;j<seed_to_soil.size();j++){
                if(seed_to_soil[j][1]<=seed[i] && seed[i]<=seed_to_soil[j][1]+seed_to_soil[j][2]-1){
                    soil[i]=seed[i]-seed_to_soil[j][1]+seed_to_soil[j][0];
                    k+=seed_to_soil[j][1]+seed_to_soil[j][2]-1-seed[i];
                    //seed[i]=seed_to_soil[j][1]+seed_to_soil[j][2];
                    cout<<range[i]-k<<',';
                    break;
                }
            }
            if(soil[i]==-1)soil[i]=seed[i];

            for(int j=0;j<soil_to_fertilizer.size();j++){
                if(soil_to_fertilizer[j][1]<=soil[i] && soil[i]<=soil_to_fertilizer[j][1]+soil_to_fertilizer[j][2]-1){
                    fertilizer[i]=soil[i]-soil_to_fertilizer[j][1]+soil_to_fertilizer[j][0];
                    break;
                }
            }
            if(fertilizer[i]==-1)fertilizer[i]=soil[i];

            for(int j=0;j<fertilizer_to_water.size();j++){
                if(fertilizer_to_water[j][1]<=fertilizer[i] && fertilizer[i]<=fertilizer_to_water[j][1]+fertilizer_to_water[j][2]-1){
                    water[i]=fertilizer[i]-fertilizer_to_water[j][1]+fertilizer_to_water[j][0];
                    break;
                }
            }
            if(water[i]==-1)water[i]=fertilizer[i];

            for(int j=0;j<water_to_light.size();j++){
                if(water_to_light[j][1]<=water[i] && water[i]<=water_to_light[j][1]+water_to_light[j][2]-1){
                    light[i]=water[i]-water_to_light[j][1]+water_to_light[j][0];
                    break;
                }
            }
            if(light[i]==-1)light[i]=water[i];

            for(int j=0;j<light_to_temperature.size();j++){
                if(light_to_temperature[j][1]<=light[i] && light[i]<=light_to_temperature[j][1]+light_to_temperature[j][2]-1){
                    temperature[i]=light[i]-light_to_temperature[j][1]+light_to_temperature[j][0];
                    break;
                }
            }
            if(temperature[i]==-1)temperature[i]=light[i];

            for(int j=0;j<temperature_to_humidity.size();j++){
                if(temperature_to_humidity[j][1]<=temperature[i] && temperature[i]<=temperature_to_humidity[j][1]+temperature_to_humidity[j][2]-1){
                    humidity[i]=temperature[i]-temperature_to_humidity[j][1]+temperature_to_humidity[j][0];
                    break;
                }
            }
            if(humidity[i]==-1)humidity[i]=temperature[i];

            for(int j=0;j<humidity_to_location.size();j++){
                if(humidity_to_location[j][1]<=humidity[i] && humidity[i]<=humidity_to_location[j][1]+humidity_to_location[j][2]-1){
                    location[i]=humidity[i]-humidity_to_location[j][1]+humidity_to_location[j][0];
                    break;
                }
            }
            if(location[i]==-1)location[i]=humidity[i];
            if(minimum[i]>location[i])minimum[i]=location[i];   
        }
        cout<<endl;
    }
    ll min=minimum[0];
    for(int i=0;i<n;i++){
        cout<<minimum[i]<<" ";
        if(location[i]<min){
            min=minimum[i];
        }
    }
    cout<<min;


    
    


    return 0;
}
