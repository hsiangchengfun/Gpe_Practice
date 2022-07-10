#include<iostream>
#include<vector>
#include<string>
#include<set>
#define ll long long 

using namespace std;


int main(){
    cin.tie(0);cin.sync_with_stdio(0);

    string a,b;
    while(cin>>a>>b){
        multiset<char> sett;
        multiset<char> aaa;
        for(ll i=0;i<a.length();i++){
            aaa.insert(a[i]);
        }

        for(ll i=0;i<b.length();i++){
        multiset<char>::iterator itr = aaa.find(b[i]);
            if(itr!=aaa.end())sett.insert(b[i]);
        }
        for(multiset<char>::iterator itr=sett.begin();itr!=sett.end();itr++){
            cout<<(char)*itr;
        }
        a="";
        b="";

        cout<<"\n";
    }
    
    
    return 0;
}