//Eb Alto Saxophone Player	
//Contributer : Chuo Min Yang
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string strs[] = {   "c0111001111", "d0111001110",
                        "e0111001100", "f0111001000",
                        "g0111000000", "a0110000000",
                        "b0100000000", "C0010000000",
                        "D1111001110", "E1111001100",
                        "F1111001000", "G1111000000",
                        "A1110000000", "B1100000000"
                    };
    vector<string> table(strs, strs+(sizeof(strs)/sizeof(string)));
    string n; int int_n;
    getline(cin, n);
    stringstream ss(n);
    ss >> int_n;
    for(int i = 0; i < int_n; ++i){
        string next;
        string current = "0000000000"; 
        vector<int> count(10, 0);
        string s; 
        getline(cin, s);

        for(int j = 0; j < s.length() && s[j] != ' '; ++j){
            for(int k = 0; k < 14; ++k){
                if(s[j] == table[k][0]){
                    next = table[k].substr(1, 10);
                }
            }
            for(int k = 0; k < 10; ++k){
                if(current[k] == '0' && next[k] == '1'){
                    count[k]++;
                }
            }
            current = next;                
        } 
        for(int j = 0; j < 9; ++j){
            cout << count[j] << " ";
        }
        cout << count[9] << '\n';
    }
    return 0;
}

/*
題解:
本題只要計算每個音符會用到的按鍵
並且考慮到如果前一次有按的話此次就不能計入

作法:
將所有音符以及其按鍵包成 string array
包含音符及其按鍵

接著另外設立 current 以及 next
跑一層迴圈 比對前一次和當下那次是否有重複用到的按鍵
與前一次沒有重複才能把 count++


*/