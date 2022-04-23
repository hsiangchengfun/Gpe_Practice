#include<iostream>
#include<vector>
#include<set>
#include<string>
#define ll long long
using namespace std;

int main(){
	string a,b;
	while(cin>>a>>b){
		multiset<char> sa,sb,s;
		vector<ll> va(26,0),vb(26,0);
		for(ll i=0;i<a.size();i++){sa.insert(a[i]);va[a[i]-'a']++;}
		for(ll i=0;i<b.size();i++){sb.insert(b[i]);vb[b[i]-'a']++;}
		
		for(ll i=0;i<26;i++){
			if(va[i]>vb[i])va[i]=vb[i];
			//ll mx = max(va[i],vb[i]);
			while(va[i]--){
				s.insert((char)('a'+i));
			}
		}
		for(multiset<char>::iterator itr=s.begin();itr!=s.end();itr++){
			cout<<*itr;
		}
		cout<<"\n";
	
	}

	return 0;
}
