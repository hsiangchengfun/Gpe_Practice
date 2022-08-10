//Conformity	
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;


int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	ll n;
	while(cin>>n){
		map<ll,ll> mp;
		if (n == 0){break;}
		
		vector<ll> vec(5,0);
		for(ll i=0;i<n;i++){
			ll course = 0;
			for(ll j=0;j<5;j++)cin>>vec[j];
			sort(vec.begin(),vec.end());
			for(ll j=0;j<5;j++){
				course *=1000;
				course +=vec[j];
			}
			mp[course]++;
		}		
		ll mx =0;
		for(map<ll,ll>::iterator itr= mp.begin();itr!=mp.end();itr++){
			mx =max(mx,itr->second);
		}
		ll ans = 0;
		for(map<ll,ll>::iterator itr = mp.begin();itr!=mp.end();itr++){
			if(itr->second == mx )ans+=mx;
		}
		cout<<ans<<"\n";

	}


	return 0;
}



