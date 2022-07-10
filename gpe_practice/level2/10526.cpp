#include<iostream>
#include<vector>
#include<string>
#define ll long long
using namespace std;


vector<ll> strtovec(string str){
    vector<ll> vec;
    for(ll i=0;i<str.length();i++){
        vec.push_back(str[i]);
    }


    return vec;
}

string vectostr(vector<ll> vec){
    string str;
    for(ll i=0;i<vec.size();i++){
        str+=vec[i]+48;
    }

    return str;
}

void calcu(vector<ll>& a,vector<ll>& b){

    ll tt=a.size()+b.size();

    vector<ll> tmp(tt-1);
    cout<<"tmp size "<<tmp.size();

    for(ll j=b.size()-1;j>=0;j--){
        for(ll i=a.size()-1;i>=0;i--){
            tmp[i+j]+=a[i]*b[j];            
        }
    }

    for(ll i=tmp.size()-1;i>=0;i--){
        if(tmp[i] > 10){
            ll t =tmp[i];
            tmp[i]%=10;
            tmp[i-1]+=t/10;
        }
    }

    string t = vectostr(tmp);
    cout<<t;

}




int main(){

    cin.tie(0);
    cin.sync_with_stdio(0);

    string str1,str2;
    while(1){
        getline(cin,str1);
        getline(cin,str2);
        vector<ll> vec1=strtovec(str1);
        vector<ll> vec2=strtovec(str2);
        calcu(vec1,vec2);
    }
    


    return 0;
}