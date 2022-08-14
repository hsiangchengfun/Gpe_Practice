//All in All
#include<iostream>
#include<vector>
#include<string>
#define ll long long
using namespace std;



vector<vector<int>> vec;

int main(){

    cin.tie(0);
    cin.sync_with_stdio(0);


    string a,b;


    while(cin>>a>>b){
    
        a = " "+a;
        b = " "+b;
        vec.resize(a.length(),vector<int>(b.length(),0));

        for(ll i=1;i<=a.length()-1;i++){
            for(ll j=1;j<=b.length()-1;j++){
                if(a[i]==b[j])vec[i][j] = vec[i-1][j-1] + 1;
                else {
                    vec[i][j] = max( vec[i-1][j], vec[i][j-1]);
                }
                // cout<<"a";
            }

        }

        if(vec[a.length()-1][b.length()-1]==a.length()-1)cout<<"yes\n";
        else cout<<"no\n";


    }


    return 0;
}


/*
題解:
本題在於要找出前字串是否為後字串的子字串
因此只要利用檢查 substring 解法就能解決

作法:
建立一個二維 vector 用來存有 match 到的長度
將兩字串分別在最前面加一個空格

substring 常用解法:
兩層迴圈 如果兩 a[i] 和 b[j] 相等
就將 vector[i][j] 賦值 vector[i-1][j-1] + 1 
若無 則給予 vector[i-1][j] vector[i][j-1] 較大者

最後只要確認 vector 最末格是否等於前字串長度
就能知道是否有整個前字串 match 到後字串


*/