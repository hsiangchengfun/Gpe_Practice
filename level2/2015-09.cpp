#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

ll LIS(vector<ll> vec){
    vector<ll> res;
    // ll pos=0,val=0;
    for(ll i=0;i<vec.size();i++){

        vector<ll>::iterator itr = std::lower_bound(res.begin(),res.end(),vec[i]);
        if( itr == res.end() )res.push_back(vec[i]);
        else (*itr)=vec[i];

    }

    return res.size();

}


int main(){

    ll N;
    cin>>N;
    vector<ll> vec;
    ll a;
    while(N--){
        cin>>a;
        vec.push_back(a);
    }
    ll ans = LIS(vec);
    cout<<ans<<"\n";



}