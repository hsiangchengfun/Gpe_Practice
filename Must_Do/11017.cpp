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