//Reverse and Add
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;


vector<ll> inttovec(ll a){
    vector<ll> vec;
    ll t = a;
    for(ll i=0;i<(int)log10(a)+1;i++){
        vec.push_back(t%10);
        t/=10;
    }
    reverse(vec.begin(),vec.end());
    return vec;


}

ll vectoint(vector<ll> vec){
    ll ans=0;
    for(ll i=0;i<vec.size();i++){
        ans=ans*10+vec[i];
    }
    // cout<<"ans "<<ans;
    return ans;

}

void calcu(ll M){
    vector<ll> vec1,vec2;
    ll t=M;
    vec1=inttovec(M);
    vec2=vec1;

    reverse(vec2.begin(),vec2.end());


    ll tmp=0;
    while(1){

        ll a,b;
        a=vectoint(vec1);
        b=vectoint(vec2);

        vec1.resize(0);
        vec2.resize(0);
        tmp++;
        
        a+=b;
        

        vec1=inttovec(a);
        vec2=vec1;
        reverse(vec2.begin(),vec2.end());
       

        ll ans1=vectoint(vec1);
        ll ans2=vectoint(vec2);
        if(ans1==ans2){cout<<tmp<<" "<<ans1<<"\n";return;}


    }


}
int main(){

    cin.tie(0);
    cin.sync_with_stdio(0);

    ll N,M;
    cin>>N;

    while(N--){
        cin>>M;
        calcu(M);
    }

    return 0;
}