#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<utility>
#define ll long long

using namespace std;

int main(){


    cin.tie(0);
    cin.sync_with_stdio(0);
    
    // m num of word // n num of jod description

    ll m,n;
    cin>>m>>n;
    string s;
    ll val;

    map<string,ll> mp;
    //dictionary
    for(ll i=0;i<m;i++){
        cin>>s>>val;
        mp.insert(make_pair(s,val));
    }


    while(n--){
        ll ans=0;
        while(cin>>s){
            if(s == ".")break;
            map<string,ll> :: iterator itr=mp.find(s);
            if(itr!=mp.end()){
                ans+=(*itr).second;
            }
        }
        cout<<ans<<"\n";


    }

    return 0;
}