#include<iostream>
#include<string>
#define ll long long

using namespace std;

void comp(string str,int n){

    ll min=0;
    string minstr(str,0,n);
    for(ll i=0;i<n;i++){
        string a(str,i,n);
        string b(str,i+1,n);
        if(a<b && a<minstr){minstr=a;min=i;}
        else if(a>b && b<minstr) {minstr=b;min=i+1;}

    }
    cout<<min+1<<endl;

}


int main(){

    ll n;
    cin>>n;
    while (n--)
    {
        string s;
        cin>>s;

        comp(s+s,s.length());

    }
    



    return 0;
}