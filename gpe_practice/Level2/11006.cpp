#include<iostream>
#include<vector>
#define ll long long 

using namespace std;
vector<vector<char> > vec(25,vector<char>(25));
vector<vector<bool> > visited(25,vector<bool>(25,0));
void DFS(ll x,ll y);
int main(){
	
	ll n;
	cin>>n;
	ll h,w,maxarea;
	for(ll i=1;i<=n;i++){
		cin>>h>>w;
		for(ll j=1;j<=h;j++){
			for(ll k=1;k<=w;k++){
				cin>>vec[j][k];
			}
		}
		maxarea=0;
		vector<ll> letter(26,0);
		for(ll j=1;j<=h;j++){
			for(ll k=1;k<=w;k++){
				if(!visited[j][k]){
					letter[vec[j][k]-'a']++;
					maxarea = max(letter[vec[j][k]-'a'],maxarea); 
					DFS(j,k);
				}
			}
		
		}

		cout<<"World #"<<i<<"\n";
		for(ll j = maxarea;j>=1;j--){
			for(ll k=0;k<26;k++){
				if(letter[k] == j)cout<<(char)(k+'a')<<": "<<j<<"\n";
			}
			
		}
	
	}


	return 0;

}


void DFS(ll x,ll y){
	visited[x][y]=true;
	if(vec[x][y+1] == vec[x][y] && !visited[x][y+1])DFS(x,y+1);
	if(vec[x][y-1] == vec[x][y] && !visited[x][y-1])DFS(x,y-1);
	if(vec[x+1][y] == vec[x][y] && !visited[x+1][y])DFS(x+1,y);
	if(vec[x-1][y] == vec[x][y] && !visited[x-1][y])DFS(x-1,y);

}
