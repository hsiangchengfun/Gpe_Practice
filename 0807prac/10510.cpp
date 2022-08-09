#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#define ll long long


using namespace std;



int main(){

    int n;
    cin>>n;
    int a,b,m;
    while(n--){
        cin>>m;
        vector<int> va(m),vb(m),ans(m);
        for(int i=m-1;i>=0;i--){
            cin>>va[i]>>vb[i];

        }

        for(int i=0;i<m;i++){
            va[i]+=vb[i];

            if(i>0 && va[i-1]>=10){
                va[i]+=va[i-1]/10;
                va[i-1]%=10;
            }
        }

        for(int i=m-1;i>=0;i--){
            cout<<va[i];
        }
        cout<<endl;







    }












    return 0;
}