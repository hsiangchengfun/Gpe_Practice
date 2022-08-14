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

/*
題解:
本題題目很難看懂
所以建議練習時看熟 考試若遇到可以很快解出來

要計算重複量最多的課 考量到課程名稱為數字
因此我們可以將課程(數字)排序 合成一條 再做比較

做法:
用 vertor 先吃入學生五門課
sort 過後直接存入 map
如此一來就能得到每種課程安排的學生分別有幾個

接著用一層迴圈計算 map 中 value 最大值 就是最多人數重複的安排數量

但題目要印出的是 所有符合"最大重複數"者
所以要再跑一次 把 value 等於前面得到這個最大值的人數都加起來
就是答案

*/



