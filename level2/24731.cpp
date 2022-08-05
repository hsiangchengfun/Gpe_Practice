#include<iostream>
#include<vector>
#include<sstream>

#define ll long long 
using namespace std;

ll longest=0;

ll DFS(ll x,ll dad,vector< vector < pair<ll,ll> > >& adj){
    ll h0=0,h1=0;
    // cout<<x<<endl;
    for(vector < pair<ll,ll> >  ::iterator itr=adj[x].begin();itr!=adj[x].end();itr++){
        if( ( *itr ).first != dad ){
            ll h = DFS((*itr).first,x,adj) + (*itr).second;
            if( h > h0 ) { h1 = h0; h0 = h; }
            else if( h > h1 ){ h1 = h; }
        }

    }
    longest = max(longest, h0 + h1 );
    return h0;
}

ll mystoi(string s){
    ll ans=0;

    ll i=0;
    while(i!=s.length()){
        ans+=s[i]-'0';
        i++;
        if(i!=s.length())ans*=10;
        
    }
    return ans;


}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);


    while(!cin.eof()){
        

        longest=0;
        ll rt=1;
        ll a,b,c;
        
        vector< vector < pair<ll,ll> > > adj(10000);
        while(1){

            string s;
            getline(cin,s);

            if(s.length()==0)break;

            stringstream sss(s);
            vector<string> strvec(3);
            ll i=0;

            while(getline(sss,strvec[i],' ')){
                i++;
            }

            stringstream ss;

            a=mystoi(strvec[0]);
            b=mystoi(strvec[1]);
            c=mystoi(strvec[2]);

            
            adj[a].push_back(make_pair(b,c));
            adj[b].push_back(make_pair(a,c));

        }
        DFS(rt,rt,adj);
        
        cout<<longest<<"\n";



    }

    



    return 0;
}