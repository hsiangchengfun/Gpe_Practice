//Product of digits
#include<iostream>
#include<vector>
#include<set>
#define ll long long

using namespace std;

ll calcu(ll n){
    ll ans=0;
    multiset<ll> s;
    ll t = n;
    ll i=9;
    ll x=1;
    bool flag=0;
    if(n==1){cout<<1<<endl;return 0;}
    while(i>1){
        if(n % i == 0){ 
            n = n / i;
            s.insert(i);
            x*=i;
        }
        i--;
        if(n % (i+1) == 0){ 
            i++;
        }
    }

    if(x == t)flag=1;

    
    if(flag){
        for(multiset<ll>::iterator itr= s.begin(); itr!= s.end();itr++){
            cout<<*itr;
        }
    }
    else {
        cout<<-1;
    }
    cout<<endl;

    return 0;
}

int main(){

    cin.tie(0);
    cin.sync_with_stdio(0);
    ll T;
    ll N;
    cin>>T;

    while(T--){
        cin>>N;
        calcu(N);
    }


    return 0;
}

/*
題解:
本提要求印出 能乘出此數字 的排列組合中最大值
因此只要找到所有個位數因數並從大排到小即可

做法:
將原數字不斷除以 i 
i 由 9 開始遞減
每次遞減完先檢查是否能再除以遞減前的 i 一次
若可以則將 i++ 回去
上述過程每次都將得到的因數添入一 multiset 並且另外乘起來
這裡使用 multiset 而非 set 是因為 multiset 允許重複值 而因數可能重複

最後判斷若乘積等於原本的值
則由大到小印出
否則輸出 -1
*/