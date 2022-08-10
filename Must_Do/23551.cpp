//Largest Square	
#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long

using namespace std;

ll M,N,Q;
ll  calcu(vector<vector<char> >& vec,ll fst,ll sec){

    ll ans=1;
    if(fst == 0 || fst == M-1 || sec == 0 || sec == N-1 )return 1;

    char tg = vec[fst][sec];
    // cout<<tg<<endl;
    for(ll k=1;fst-k>=0 && fst+k<=M-1 && sec-k>=0 && sec+k<=N-1;k++){
        for(ll i=fst-k;i<=fst+k;i++){
            for(ll j=sec-k;j<=sec+k;j++){
                if(vec[i][j] != tg)return ans;
            }
        }        
        ans = 2*k+1;
    }


    
    return ans;

}


int main(){

    cin.tie(0);
    cin.sync_with_stdio(0);

    ll t;


    cin>>t;
    while(t--){
        cin>>M>>N>>Q;

        vector< vector<char> > vec( M , vector<char> ( N ,'a'));

        for(ll i=0;i<M;i++){
            for(ll j=0;j<N;j++){
                cin>>vec[i][j];        
            }
        }

        ll fst,sec;

        cout<<M<<" "<<N<<" "<<Q<<"\n";

        for(ll i=0;i<Q;i++){
            cin>>fst>>sec;
            ll ans = calcu(vec,fst,sec);
            cout<<ans<<"\n";
        }
    }





    return 0;
}