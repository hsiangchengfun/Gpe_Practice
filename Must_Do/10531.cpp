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


/*
題解:
這題其實就是紀錄所有單辭出現過的數量
然後印出符合指定數量的單詞即可

作法:
我這題的做法偏麻煩
先用 string 吃進來
再一個一個字判斷是否介於 'a' 到 'z' 及 'A' 到 'Z'
( 上面這步其實可以用 isupper 跟 islower )
接著判斷最後一位若是標點符號要記得去掉
然後丟進一個 map 裡面
key 為單詞
value 為出現次數

因為要排序 所以後面用一個 set 來存
將所有 value 符合題目要求的次數的 key 存入
最後印出即可

*/