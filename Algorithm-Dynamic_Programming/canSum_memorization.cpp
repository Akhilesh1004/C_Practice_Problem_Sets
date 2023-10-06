#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

bool cansum(int n, vector<int> arrays, map<int, bool>&memo){
    if(n==0) return true;
    if(n<0) return false;
    if(memo.find(n)!=memo.end()) return memo[n];
    memo[n] = false;
    for(int x : arrays){
        if(cansum(n-x, arrays, memo)){
            memo[n] = true;
        }
    }
    return memo[n];
}

int main(){
    int n, m;
    while(cin>>n>>m){
        vector<int>a(m);
        for(int i = 0; i<m; i++){
            cin>>a[i];
        }
        map<int, bool>memo;
        cout<<cansum(n, a, memo)<<endl;
    }
    return 0;
}