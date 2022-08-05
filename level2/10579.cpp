#include<iostream>
#include<vector>
#include<map>
#include<string>
#define ll long long
using namespace std;

int main(){
	ll a,b;
	cin>>a>>b;
	string str;
	ll sal;
	map<string,ll> dict;
//	map<string,ll> freq;
	while(a--){
		cin>>str>>sal;
		dict[str]=sal;
	}
	while(b--){
		ll ans=0;
		string s;
		while(cin>>s){
			if(s==".")break;
			map<string,ll>::iterator itr=dict.find(s);
			if(itr!=dict.end())ans+=itr->second;
		}
		cout<<ans<<"\n";
	}
	

	return 0;
}
