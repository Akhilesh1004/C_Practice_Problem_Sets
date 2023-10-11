#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

int countconstruct(string n, vector<string>&arrays, map<string ,int>&memo){
    if(n.empty()) return 1;
    if(memo.find(n) != memo.end()) return memo[n];
    memo[n] = 0;
    for(string x : arrays){
        if(n.find(x) == 0){
            string n_ = n.substr(x.size());
            memo[n] += countconstruct(n_, arrays, memo);
        }
    }
    return memo[n];
}

int main(){
    int m;
    string n;
    while(cin>>n>>m){
        vector<string>a(m);
        for(int i = 0; i<m; i++){
            cin>>a[i];
        }
        map<string, int>memo;
        cout<<countconstruct(n, a, memo)<<endl;
    }
    return 0;
}