//Hartals
#include<iostream>
#include<vector>
#include<set>
#define ll long long
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	ll T,N,P;
	cin>>T;
	while(T--){
		vector<ll> h;
		cin>>N>>P;
		h.resize(P);
		
		for(ll i=0;i<P;i++){
			cin>>h[i];	
		}
		set<ll> s;
		for(ll i=1;i<=N;i++){
			for(ll j=0;j<P;j++){
				if((i%h[j]==0) && (i%7 !=6)&& (i%7!=0)){
					s.insert(i);
				}
			}	
		}
		cout<<s.size()<<"\n";	
		
	}

	return 0;
}

/*
題解:
本題只要考慮到是放假週期的倍數 並且不能計入週末 因為本來就是放假 不算cost

做法:
用 vector 存入所有放假週期
雙層迴圈
外層 run 過全部天數
內層歷遍所有週期 只要日期 mod 週期為零 且非週六週日
則添入 set
此處用 set 是因為日期會重複
但是我們要計算天數(相異) 可以直接利用 set 的長度就好
因此不需要用 multiset 否則會多算
*/