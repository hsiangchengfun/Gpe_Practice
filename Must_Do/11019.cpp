//Die Game	
#include<iostream>
#include<vector>
#include<string>
#define ll long long 
using namespace std;
void calcu(vector<vector<ll> >& v,char direct){
	
	if(direct == 'n'){
		ll t=v[0][1];
		v[0][1]=v[1][1];
		v[1][1]=v[2][1];
		v[2][1]=v[3][1];
		v[3][1]=t;
	}
	else if(direct == 's'){
                ll t=v[3][1];
                v[3][1]=v[2][1];
                v[2][1]=v[1][1];
                v[1][1]=v[0][1];
                v[0][1]=t;
        }
	else if(direct=='e'){
		ll t = v[0][0];
		v[0][0]=v[2][1];
		v[2][1]=v[0][2];
		v[0][2]=v[0][1];
		v[0][1]=t;
	}
	else{
                ll t = v[0][0];
                v[0][0]=v[0][1];
                v[0][1]=v[0][2];
                v[0][2]=v[2][1];
                v[2][1]=t;
        }


	
}
int main(){
	
	ll n;
	while(cin>>n){
	
		if(n == 0) break;
		vector<vector<ll> > v(4,vector<ll> (3,0));
		v[0][0]=3;
		v[0][1]=1;
		v[0][2]=4;
		v[1][1]=5;
		v[1][2]=6;
		v[1][3]=2;
		vector<string> vec(n);
		for(ll i=0;i<n;i++){
			cin>>vec[i];
		}
		ll ans=1;
		for(ll i=0;i<n;i++){
			calcu(v,vec[i][0]);
		}

		cout<<v[0][1]<<"\n";
	
	
	}

	return 0;
}
