#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define ll long long


using namespace std;


int main(){


    ll N;
    cin>>N;

    while(N--){
        ll a,tmp;
        cin>>a;
        tmp = a;
        ll x=1;
        string ans;
        int i=9;
        if(a == 1){cout<<1<<"\n";continue;}

        while(i != 1){
            if(a%i==0){
                ans += (i+'0');
                a /= i;
                x *= i;
            }
            i--;

            if(a%(i+1)==0)i++;
        }
        sort(ans.begin(), ans.end());
        if(x == tmp)cout<<ans<<"\n";
        else cout<<-1<<"\n";
        
    }





    return 0;
}