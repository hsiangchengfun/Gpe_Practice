#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define ll long long

using namespace std;
int main(){
	ll a;
	vector<ll> v;
	multiset<ll> s;
	while(cin>>a){
		v.push_back(a);
		s.insert(a);
		ll ans=0;
		
		sort(v.begin(),v.end());	
		ll ind = s.size()/2;
		
		if(v.size()%2 == 0){
			ans =( v[ind]+v[ind-1])/2;		
		}
		else ans = v[ind];
		
		cout<<ans<<"\n";
	
	}

	return 0;
}
