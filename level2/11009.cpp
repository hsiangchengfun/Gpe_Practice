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