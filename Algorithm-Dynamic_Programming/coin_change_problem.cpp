#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int coinchange(int n, vector<int>coins, map<int, int>&memo){
    if(n < 0) return -1;
    if(n == 0) return 0;
    if(memo.find(n) != memo.end()) return memo[n];
    int minCoin = 9e8;
    for(int x : coins){
        int value = coinchange(n-x, coins, memo);
        if(value != -1 && value<minCoin) minCoin = value+1;
    }
    if(minCoin == 9e8) memo[n] = -1;
    else memo[n] = minCoin;
    return memo[n];
}

int main(){
    int n, m;
    while(cin>>n>>m){
        vector<int>coins(m);
        for(int i = 0; i<m; i++){
            cin>>coins[i];
        }
        map<int, int>memo;
        cout<<coinchange(n, coins, memo)<<endl;
    }
}