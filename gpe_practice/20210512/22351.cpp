#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<cmath>
#define ll long long


using namespace std;

vector<ll> vec(10000);
void calcu(vector< vector<ll> >& ans){

    for(ll i=0;i<10000;i++){
        vec[i]=i*i;
    }
    ll flag=0;
    
    ll a = 1,b = 1;
    for(ll i=0;i<10000;i++){
        if(vec[i]>100)break;
        if(vec[i]<10){
            a=0;
            b=vec[i];
        }
        else if(vec[i]<100){
            a=vec[i]/10;
            b=vec[i]%10;
        }
       
        if( pow(a+b,2) == vec[i] ){
            ans[0].push_back(vec[i]);
        }

    }

    for(ll i=0;i<10000;i++){
        if(vec[i]>10000)break;
        //if(vec[i]<1000)continue;

        if(vec[i]<10000){
            a=vec[i]/100;
            b=vec[i]%100;
        }
       
        if( pow(a+b,2) == vec[i] ){
            ans[1].push_back(vec[i]);
        }

    }
    
    for(ll i=0;i<10000;i++){
        if(vec[i]>1000000)break;
        //if(vec[i]<100000)continue;

        if(vec[i]<1000000){
            a=vec[i]/1000;
            b=vec[i]%1000;
        }
       
        if( pow(a+b,2) == vec[i] ){
            ans[2].push_back(vec[i]);
        }

    }

    for(ll i=0;i<10000;i++){
        if(vec[i]>100000000)break;
        //if(vec[i]<10000000)continue;

        if(vec[i]<100000000){
            a=vec[i]/10000;
            b=vec[i]%10000;
        }
       
        if( pow(a+b,2) == vec[i] ){
            ans[3].push_back(vec[i]);
        }

    }


    
}



int main(){

    cin.tie(0);
    cin.sync_with_stdio(0);

    vector< vector<ll> > ans(4);
    calcu(ans);

    ll n;
    while(cin>>n){
        for(ll i=0 ; i<ans[(n-2)/2 ].size() ; i++){

            cout<<setfill('0')<<setw(n)<<ans[(n-2)/2 ][i]<<"\n";
        }
    }







    return 0;
}