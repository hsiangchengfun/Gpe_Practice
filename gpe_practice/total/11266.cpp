#include<iostream>
#include<vector>
#include<string>
#include<sstream>

#define ll long long

using namespace std;

int generator(int n){

    vector<bool> found(10001,0);
    int ans = 0;

    while(1){

        n = n*n;
        stringstream ss;
        ss<<n;


        string tmp = ss.str();//to_string(n);
        string zero = "00000000";
        string a(zero,0, 8 - tmp.length() );
        a += tmp;
        //cout<<a<<endl;
        string four(a,2,4);
        
        stringstream sss;
        sss<<four;

        int t;
        sss>>t;
        //int t = stoi(four);
        
        if(found[t])break;
        found[t]=1;
        //cout<<t<<endl;
        n = t;
        ans++;

        
    }

    return ans+1;
}



int main(){




    ll n;
    while(cin>>n){
        if(n == 0)break;

        int ans = generator(n);
        cout<<ans<<"\n";
    }


    //system("pause");
    return 0;
}