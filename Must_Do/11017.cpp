//Longest Common Subsequence	
#include<iostream>
#include<vector>
#include<string>

#define ll long long

using namespace std;

ll lcs(string a,string b){

    a=" "+a;
    b=" "+b;



    vector<ll> vecb(b.length()+1,0);
    vector< vector<ll> > vec(a.length()+1,vecb);

    for(ll i=1;i<=a.length();i++){
        for(ll j=1;j<=b.length();j++){
            if(a[i] == b[j]){
                vec[i][j]=vec[i-1][j-1]+1;
            }
            else {
                vec[i][j] = max( vec[i][j-1],vec[i-1][j] );
            }


        }
    }

    return vec[a.length()][b.length()];
}





int main(){

    cin.tie(0);
    cin.sync_with_stdio(0);

    string a,b;
    while(cin>>a){
        
        cin>>b;
        ll ans = lcs(a,b)-1;
        cout<<ans<<"\n";
    }





    return 0;
}



/*
題解:
本題只要利用檢查 substring 解法就能解決

作法:
建立一個二維 vector 用來存有 match 到的長度
將兩字串分別在最前面加一個空格

substring 常用解法:
兩層迴圈 如果兩 a[i] 和 b[j] 相等
就將 vector[i][j] 賦值 vector[i-1][j-1] + 1 
若無 則給予 vector[i-1][j] vector[i][j-1] 較大者

最後只要確認 vector 最末格就能知道前字串 match 到後字串的長度


*/