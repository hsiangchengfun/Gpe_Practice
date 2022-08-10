//Zipf's Law	
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#define ll long long

using namespace std;

int main(){
	
	ll n;
	cin>>n;
	string a;
	map<string ,ll> dict;
	while(1){
		cin>>a;
		if(a == "EndOfText")break;
		string::iterator it0 = a.begin()+0;
		if(!(a[0]>='A'&&a[0]<='Z') && !(a[0]>='a' && a[0]<='z'))a.erase(it0);

		if(a[0]<='Z' && a[0]>='A')a[0]+=32;
		string :: iterator it = a.begin()+a.size()-1;
		if(a[a.size()-1] >='z' || a[a.size()-1] <='a')a.erase(it);
		if(a[0]>='a'&& a[0]<='z')dict[a]++;
	}
	set<string> s;

	for(map<string,ll>::iterator itr = dict.begin();itr!=dict.end();itr++){
			
		if(dict[itr->first]==n)s.insert(itr->first);
	}
	
	for(set<string>::iterator itr=s.begin();itr!=s.end();itr++){
		cout<<*itr<<"\n";
	}
	if(s.size()==0)cout<<"There is no such word.\n";

	return 0;
}
