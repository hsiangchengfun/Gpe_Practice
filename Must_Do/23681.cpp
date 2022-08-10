//Bachet's Game	
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<utility>
#include<algorithm>
#define ll long long

using namespace std;


ll knap(vector<ll>& weight,ll m,ll n){
    // s == m
    // w == n 

    vector<ll> dp(n+1,0);
    /*for(ll i=0;i<m;i++){
        for(ll j=n;j>=0;j--){
            if( j >= weight[i]  && dp[ j - weight[i] ] == 0  ) dp[j] = 1;

        } 
    }*/

    for(ll i=1;i<=n;i++){// for all stones
        for(ll j=0;j<m;j++){// try all weight
            if( i >= weight[j] && dp[i - weight[j]] == 0){ dp[i] = 1; break;}
        }
    }
    

    return dp[n];


}

int main(){


    cin.tie(0);
    cin.sync_with_stdio(0);
    
    // n stones on table
    // m nums follow


    ll n,m;
    while(cin>>n>>m){
        //cin>>m;
        //cin>>n>>m;
        vector<ll> weight(m);

        for(ll i=0;i<m;i++)cin>>weight[i];
        sort(weight.begin(),weight.end());
        
        ll ans = knap(weight,m,n);
        if(ans)cout<<"Stan wins\n";
        else cout<<"Ollie wins\n";


    }



    return 0;
}