#include<iostream>
#include<vector>
#include<string>
#define ll long long

using namespace std;

int main(){

    vector<vector<ll>> a(301,vector<ll> (500,0));
    vector<ll> b(301,0);


    a[1][0]=1;
    a[0][0]=0;
    b[1]=1;

    ll len=1;
    //times
    for(ll i=1;i<=300;i++){
        ll carry=0;
        for(ll j=0;j<len;j++){
            
            a[i][j]=a[i-1][j] * ( 4 * (i - 1) + 2)*i;
        }

        for(ll j=0;j<len;j++){

            ll tmp=a[i][j] + carry;
            a[i][j] = tmp % 10;;
            carry = tmp / 10;

        }
        // left carry
        while(carry){
            a[i][len++] = carry % 10;
            carry /= 10;
        }

        carry =0;

        for(ll j=len-1;j>=0;j--){
            
            ll tmp = carry * 10 + a[i][j];
            a[i][j] = tmp / i + 1;
            carry = tmp %  (i + 1);
        }

        while(!a[i][len-1]){
            len--;
        }
        b[i]=len;
        
    }
    

    ll n;

    while(cin>>n){
        if(n == 0)break;
        for(ll i=b[n]-1;i>=0;i--){
            cout<<a[n][i];
        }
        cout<<"\n";
    }


    return 0;
}