#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define ll long long 
using namespace std;

int main(){
	
	string a,b;
	while(cin>>a>>b){
//		cin>>a>>b;
		vector<ll> va(a.size()+b.size(),0),vb(a.size()+b.size(),0);
		for(ll i=0;i<a.size();i++)va[i]=(a[a.size()-i-1]-'0');
		for(ll i=0;i<b.size();i++)vb[i]=(b[b.size()-i-1]-'0');
		vector<ll> vec(a.size()+b.size(),0);
		for(ll i=0;i<a.size();i++){
			for(ll j=0;j<b.size();j++){
				vec[i+j]+=va[i]*vb[j];
			}
		}
		ll tmp = vec.size();
		for(ll i=0;i<tmp;i++){
			if(vec[i]>=10){
				if(i==tmp-1){
					vec.push_back(vec[i]/10);
					vec[i]%=10;
					break;
				}
				vec[i+1] += vec[i]/10;
				vec[i] %= 10;
			}
		}
		for(ll i=vec.size()-1;i>=0;i--){
			if(i == vec.size()-1 && vec[i]==0)continue;
			cout<<vec[i];
		}
		cout<<endl;
	}
	return 0;
}
