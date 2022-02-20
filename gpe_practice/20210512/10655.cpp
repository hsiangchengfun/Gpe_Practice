#include<iostream>
#include<vector>
#include<set>

#define ll long  long

using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n;
    while(cin>>n){
        if(n==0)break; 

        set<ll> s;
        vector<ll> vec;
        ll a;
        ll t=n;
        while(t--){
            cin>>a;
            vec.push_back(a);
            s.insert(a);
        }

        bool flag=0;
        ll M=-536870912;
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                for(ll k=j+1;k<n;k++){
                    ll tmp = vec[i]+vec[j]+vec[k];
                    if( s.find(tmp) != s.end() ){
                        // cout<<tmp<<"\n";
                        M=max(M,tmp);
                        flag=1;
                    }
                    
                }
            }
        }
        if(flag)cout<<M<<"\n";
        else cout<<"no solution\n";
    }

    


    return 0;
}