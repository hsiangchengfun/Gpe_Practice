#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#define ll long long

using namespace std;

int main(){
    
    cin.tie(0);
    cin.sync_with_stdio(0);

    set<ll> prime;
    set<ll> dgp;

    prime.insert(2);
    prime.insert(3);

    for(ll i=3;i<=1000000;i++){
        for(ll j=2;j<=sqrt(i);j++){
            if(i%j == 0){
                break;
            }
            if(j == (int)sqrt(i)){
                prime.insert(i);

            }
        }
        
    }

    for(ll i=2;i<1000000;i++){
        ll tmp=0,t=i;
        if( prime.find(i)==prime.end() ){
            continue;
        }
        while(t!=0){
            tmp += t%10;
            t /= 10;
        }
        if( prime.find(tmp)!=prime.end() ){
            dgp.insert(i);
        }

    }
    
    ll n,m;
    ll A;
    cin>>A;
    while(A--){
        cin>>n>>m;
        set<ll> ::iterator itr1 = dgp.lower_bound(n);
        set<ll> ::iterator itr2 = dgp.upper_bound(m);
        ll ans=0;
        while(*itr1 != *itr2){
            itr1++;
            ans++;
        }
        cout<<ans<<"\n";
    }

    


    return 0;
}