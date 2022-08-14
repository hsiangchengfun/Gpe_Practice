//Hay Points	
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

/*
題解:
本題只要先將單詞和錢錢存成 map
最後每吃到一個 string 就查找 如果出現過就加起來即可

作法:
將 單詞 存成 key
   錢錢 存成 value

一旦吃盡 string 就檢查是否再 map 裡面
如果找到就把答案 += value


*/
