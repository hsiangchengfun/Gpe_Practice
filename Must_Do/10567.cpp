//Common Permutation	
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


/*
這題要印出兩個字串彼此重複的所有元素
並且可會有同字母多次的情形
因此只要分別記錄每個字母在字串中有幾次
取較小值即可

作法:
用兩個 string 先存入
再用一層迴圈將字串的元素丟入各自的 vector
若是 a 則丟入 0
若是 b 則丟入 1
依此類推

隨後用一個 for 由 i = 0 ~ i = 25
得到兩字串中該元素較小值( 18 行 )
並將該元素照該次數丟入 multiset (因為後面要照順序印 而且可能會有同字母多次出現所以用 multiset )
最後將 multiset 內容印出即可


*/