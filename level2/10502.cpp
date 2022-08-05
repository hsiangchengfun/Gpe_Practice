#include<iostream>
#include<vector>
#include<set>
#define ll long long

using namespace std;

ll calcu(ll n){
    ll ans=0;
    multiset<ll> s;
    ll t = n;
    ll i=9;
    ll x=1;
    bool flag=0;
    if(n==1){cout<<1<<endl;return 0;}
    while(i>1){
        if(n % i == 0){ 
            n = n / i;
            s.insert(i);
            x*=i;
        }
        i--;
        if(n % (i+1) == 0){ 
            i++;
        }
    }

    if(x == t)flag=1;

    
    if(flag){
        for(multiset<ll>::iterator itr= s.begin(); itr!= s.end();itr++){
            cout<<*itr;
        }
    }
    else {
        cout<<-1;
    }
    cout<<endl;

    return 0;
}

int main(){

    cin.tie(0);
    cin.sync_with_stdio(0);
    ll T;
    ll N;
    cin>>T;

    while(T--){
        cin>>N;
        calcu(N);
    }


    return 0;
}