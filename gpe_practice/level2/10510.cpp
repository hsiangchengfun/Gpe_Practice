#include<iostream>
#include<vector>
#include<string>
#define ll long long
using namespace std;



void calcu(vector<ll>& a,vector<ll>& b){
    ll M = a.size();
// cout<<"q";
    for(ll i=M-1;i>=0;i--){
        a[i]+=b[i];


        if(a[i] >= 0){
            ll t = a[i];
            a[i] = (t % 10);
            a[i-1] += t/10;
        }
    }
    
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    bool init=0;
    ll M,N;
    cin>>N;
    ll a,b;
    
    cout<<endl;
    for(ll i=0;i<N;i++){
        cin>>M;
        vector<ll> aa,bb;
        ll t=M;
        while(t--){
            cin>>a>>b;

            aa.push_back(a);
            bb.push_back(b);
            
        }

        calcu(aa,bb);
        for(ll j=0;j<M;j++)cout<<aa[j];

        cout<<"\n";
        if(i!=N-1)cout<<"\n";
 

        
    }


    return 0;
}