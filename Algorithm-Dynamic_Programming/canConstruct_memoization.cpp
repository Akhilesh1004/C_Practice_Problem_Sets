#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;
//O(nm) time, O(m) space
//brute force O(m^n) time, O(m) space;
bool canconstruct(string n, vector<string>&arrays, map<string, bool>&memo){
    if(n.empty())return true;
    if(memo.find(n) != memo.end()) return memo[n];
    memo[n] = false;
    for(string x : arrays){
        if(n.find(x) == 0){
            string n_ = n.substr(x.size());
            if(canconstruct(n_, arrays, memo)){
                memo[n] = true;
            }
        }
    }
    return memo[n];
}

int main(){
    int m;
    string target;
    while(cin>>target>>m){
        vector<string>a(m);
        for(int i = 0; i<m; i++){
            cin>>a[i];
        }
        map<string, bool>memo;
        cout<<canconstruct(target, a, memo)<<endl;
    }
    return 0;
}