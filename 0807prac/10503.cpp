#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#define ll long long


using namespace std;


void multi(int m,vector<int>& V){

    vector<int> S = V;
    V[0] = m * V[0];
    for(int i=1;i<V.size();i++){
        V[i] = V[i-1]*S[i];
        
    }


}

void add(int m,vector<int>& V){

    vector<int> S = V;
    V[0] = m ;
    for(int i=1;i<V.size();i++){
        V[i] = V[i-1]+S[i-1];
        
    }


}





int main(){

    string ipt;
    int len;
    while(cin>>ipt>>len){

        stack<char> ch;
        queue<int> num;
        stack<char> op;
        bool fst=1,fst2=1;
        vector<int> V;

        for(int i = ipt.length()-1; i>=0;i--){
            if(ipt[i]==']')ch.push(']');
            if(ipt[i]=='+' || ipt[i]=='*'){
                op.push(ipt[i]);
            }
            if(ipt[i]=='['){
                ch.pop();
                if(!fst2){
                    if(op.top()=='*'){
                        multi(num.front(),V);
                        num.pop();
                    }
                    if(op.top()=='+'){
                        cout<<num.front()<<endl;
                        add(num.front(),V);
                        num.pop();
                    }
                }
                fst2 = 0;

            }

            if(isdigit(ipt[i]) && !fst){
				num.push(ipt[i]-'0');
				if(ipt[i-1]=='-'){num.front()*=-1;}

			}
            if(isdigit(ipt[i]) && fst){
                num.push(ipt[i]-'0');
                if(ipt[i-1]=='-'){num.front()*=-1;}
                V.resize(len,num.front());
                num.pop();
                fst = 0;
            }
            
            
        }

        for(int i=0;i<V.size()-1;i++)cout<<V[i]<<" ";
        cout<<V[V.size()-1]<<"\n";



    }







    return 0;
}