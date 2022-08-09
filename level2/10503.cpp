#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#define ll long long


using namespace std;

void add(ll x,vector<ll>& vec){

vector<ll> tmp=vec;
	vec[0] = x;
	
	for(ll i=1;i<vec.size();i++){
		vec[i]=vec[i-1]+tmp[i-1];
	}
}
void multi(ll x,vector<ll>& vec){

	vector<ll> tmp=vec;
	vec[0] *= x;
	for(ll i=1;i<vec.size();i++){
			vec[i]=vec[i-1]*tmp[i];
	}
}

int main(){

	string ipt;
	ll num;

	while(cin>>ipt>>num){
		stack<char> c;
		stack<char> op;
		queue<ll> n;
		
		bool first=1;
		bool sec=1;

		
		vector<ll> vec;
		

		for(ll i=ipt.size()-1;i>=0;i--){
			
			if(ipt[i]==']')c.push(ipt[i]);
			if(ipt[i]=='+'|| ipt[i]=='*')op.push(ipt[i]);
			if(ipt[i]=='['){
				c.pop();
				if(!sec){
					if(op.top()=='*'){
						multi(n.front(),vec);
						n.pop();
					}
					if(op.top()=='+'){
						add(n.front(),vec);
						n.pop();
					}
				}
				sec=0;
			}
			if(isdigit(ipt[i]) && !first){
				n.push(ipt[i]-'0');
				if(ipt[i-1]=='-'){n.front()*=-1;}

			}

			if(isdigit(ipt[i]) && first){
				n.push(ipt[i]-'0');
				if(ipt[i-1]=='-'){n.front()*=-1;}
				vec.resize(num,n.front());
				n.pop();
				first=0;
			}
			// for(ll i=0;i<num-1;i++)cout<<vec[i]<<" ";
			// cout<<vec[num-1];
			// cout<<"\n";
		}
		for(ll i=0;i<num-1;i++)cout<<vec[i]<<" ";
		cout<<vec[num-1];
		cout<<"\n";
	}
	return 0;
}

