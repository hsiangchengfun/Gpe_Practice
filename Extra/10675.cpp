//Urn-ball Probabilities!	
#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>

#define ll long long

using namespace std;


vector<double> vec(1000001,0);
vector<int> digit(1000001,0);

void calcu(){
    
    double q = 1,p = 1,dg = 0;

    for(ll i=1;i<=1000000;i++){

        long double t = ( 1. / ( i * (i + 1)));//red
        q *= ( 1 - t );//no both red
        vec[i] = 1 - q;//at least one both red

        p *= t;

        dg +=log10( 1/t );

        digit[i] = (int)( dg - fmod(dg , 1));

    }
}


int main(){

    cin.tie(0);
    cin.sync_with_stdio(0);

    calcu();

    ll n;
    while(cin>>n){
        if(n==0)break;
        cout<<fixed<<setprecision(6)<<vec[n]<<" "<<digit[n]<<"\n";
    }

    return 0;
}