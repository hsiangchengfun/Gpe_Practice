//Rank the Languages	
#include<iostream>
#include<vector>

#include<algorithm>
#define ll long long 

using namespace std;
vector<vector<char> > vec;//(25,vector<char>(25));
vector<vector<bool> > visited;//(25,vector<bool>(25,0));
vector<pair<char,int>> dict;
ll h,w,maxarea;
bool comp(pair<char,int> p1,pair<char,int> p2){

	if(p1.second == p2.second)return p1.first<p2.first;
	else if (p1.second > p2.second)return true;
	else return false;

}
void DFS(ll x,ll y);
int main(){
	
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>h>>w;
		vec.clear();
		visited.clear();
		dict.clear();

		vec.resize(h+1);
		visited.resize(h+1);
		
		for(ll j=0;j<h;j++){
			vec[j].resize(w+1);
			visited[j].resize(w+1,0);
		}


		for(ll j=0;j<h;j++){
			for(ll k=0;k<w;k++){
				cin>>vec[j][k];
			}
		}
		maxarea=0;
		vector<ll> letter(26,0);
		for(ll j=0;j<h;j++){
			for(ll k=0;k<w;k++){
				if(!visited[j][k]){
					// letter[vec[j][k]-'a']++;
					
					vector<pair<char,int>>::iterator itr;
					for(itr=dict.begin();itr!=dict.end();itr++){
						if( itr->first == vec[j][k]){
							itr->second++;
							break;
						}
					}
					
					if(itr == dict.end())dict.push_back(make_pair(vec[j][k],1));
						
					


					// maxarea = max(letter[vec[j][k]-'a'],maxarea); 
					DFS(j,k);
				}
			}
		
		}

		cout<<"World #"<<i<<"\n";
		// for(ll j = maxarea;j>=1;j--){
		// 	for(ll k=0;k<26;k++){
		// 		if(letter[k] == j)cout<<(char)(k+'a')<<": "<<j<<"\n";
		// 	}
			
		// }
		sort(dict.begin(),dict.end(),comp);
		for(vector<pair<char,int>>::iterator itr = dict.begin();itr!=dict.end();itr++){
			cout<<itr->first<<": "<<itr->second<<"\n";
		}



	}


	return 0;

}


void DFS(ll x,ll y){
	visited[x][y]=true;
	if(y+1 < w && vec[x][y+1] == vec[x][y] && !visited[x][y+1])DFS(x,y+1);
	if(y-1 >= 0 && vec[x][y-1] == vec[x][y] && !visited[x][y-1])DFS(x,y-1);
	if(x+1 < h && vec[x+1][y] == vec[x][y] && !visited[x+1][y])DFS(x+1,y);
	if(x-1 >= 0 && vec[x-1][y] == vec[x][y] && !visited[x-1][y])DFS(x-1,y);

}
