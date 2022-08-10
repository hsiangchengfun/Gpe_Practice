//Power Strings	
#include<iostream>
#include<vector>


#define ll long long

using namespace std;


int main(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    string s;
    while(1){
        cin>>s;
        if(s==".")break;
        int n = s.length();
        int ans = 0;
        bool done = 0;
        int i;
        for( i=1;i<=n && !done;i++){
            if(n % i != 0)continue;
            done = 1;
            for(int j = 0;j<i && done;j++){
                for(int k = i + j;k<n ;k+=i){
                    if( s[k] != s[k-i] ){done = false;break;}
                }
            }


        }
        cout<<n/(i-1)<<"\n";



    }

    return 0;

}