// What is the Median?	
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

/*
題解:
本題要求每次的中間值
因此可以運用 set 來作為容器
考慮到數值可能重複 我們取用 multiset
但是每次要找 set 的中間值很麻煩
因此這裡我用 vector 來存然後 sort

作法:
用一層 while 迴圈不斷吃入數值並添入 vector 中
加入後進行 algorithm 的 sort
接著判斷如果元素數量為奇數則直接取 ind = (vector 長度) / 2
否則就是中間兩數平均
印出答案即可

*/
