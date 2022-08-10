//Hartals
#include<iostream>
#include<vector>
#include<set>
#define ll long long
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	ll T,N,P;
	cin>>T;
	while(T--){
		vector<ll> h;
		cin>>N>>P;
		h.resize(P);
		
		for(ll i=0;i<P;i++){
			cin>>h[i];	
		}
		set<ll> s;
		for(ll i=1;i<=N;i++){
			for(ll j=0;j<P;j++){
				if((i%h[j]==0) && (i%7 !=6)&& (i%7!=0)){
					s.insert(i);
				}
			}	
		}
		cout<<s.size()<<"\n";	
		
	}

	return 0;
}

