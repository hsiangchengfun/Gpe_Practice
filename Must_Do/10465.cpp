//Necklace
//My solution only get 80 /100
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>


#define ll long long

using namespace std;

int main(){

    multimap<ll,ll> mp;
    ll vt,v0;
    vector<bool> vec;
    while(cin>>vt>>v0){
        if( vt == 0 && v0 == 0 )break;
        mp.clear();
        vec.clear();
        vec.resize(60100,0);

        for(int i=1;i<=vt;i++){

            ll ans = i*vt - v0*i*i;
            auto itr = mp.find(ans);
            if(itr != mp.end()){
                vec[ans] = 1;
            }
            if(ans >= 0)mp.insert(make_pair(ans,i));

        }

        if(mp.size() == 0){cout<<0<<"\n";continue;}

        ll mx= 0 , maxans = 0;
        for(auto itr = mp.begin();itr != mp.end(); itr++){
            if( vec[itr->first] == false ){
                if( itr->first > mx ) maxans = itr->second;
                mx = max( itr->first , mx );
            }
        }
        cout<<maxans<<"\n";


    }


    return 0;
}