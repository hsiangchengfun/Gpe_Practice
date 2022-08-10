//Sum of Consecutive Prime Numbers	
#include<iostream>
#include<vector>
#define ll long long

using namespace std;

int main(){


    cin.tie(0);
    cin.sync_with_stdio(0);
    //2 to 10000
    vector<ll> num(10001,0);
    vector<int> nprime;//(10001,1);
    
    nprime.push_back(2);
    nprime.push_back(3);
    for(ll i=3;i<=10000;i++){
        for(ll n=2;n<=i/2;n++){
            if(i%n==0){
                break;
            }

            if(n == i/2){
                nprime.push_back(i);
            }
        }
        
    }    

    ll n;

    while(cin>>n){

        if(n == 0)break;
        ll sum = 0,ans = 0,track = 0;
        for(ll i=0; n >= nprime[i];i++){
            sum += nprime[i];
            while(sum > n){
                sum -= nprime[track];
                track++;
            }
            if(sum == n) ans++;

        }
        cout<<ans<<"\n";
    }

    return 0;
}