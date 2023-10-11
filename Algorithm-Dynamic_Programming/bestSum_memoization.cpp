#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

vector<int> bestsum(int n, vector<int>&arrays, map<int, vector<int>>&memo){
    if(n==0) return {};
    if(n<0) return {-1};
    if(memo.find(n)!=memo.end()) return memo[n];
    vector<int>shortest_combination;
    for(int x:arrays){
        int remainder = n-x;
        vector<int>remainder_combination = bestsum(n-x, arrays, memo);
        if(remainder_combination.empty() || remainder_combination[0] != -1){
            remainder_combination.push_back(x);
            if(shortest_combination.empty() || remainder_combination.size()<shortest_combination.size()){
                shortest_combination = remainder_combination;
            }
        }
    }
    if(shortest_combination.empty()){
        memo[n] = {-1};
    }else{
        memo[n] = shortest_combination;
    }
    return memo[n];
}
/*
//brute force
vector<int> bestsum(int n, vector<int>&arrays, map<int, vector<int>>&memo){
    if(n==0) return {};
    if(n<0) return {-1};
    //if(memo.find(n)!=memo.end()) return memo[n];
    vector<int>shortest_combination;
    for(int x:arrays){
        int remainder = n-x;
        vector<int>remainder_combination = bestsum(n-x, arrays, memo);
        if(remainder_combination.empty() || remainder_combination[0] != -1){
            remainder_combination.push_back(x);
            if(shortest_combination.empty() || remainder_combination.size()<shortest_combination.size()){
                shortest_combination = remainder_combination;
            }
        }
    }
    if(shortest_combination.empty()) return{-1};
    return shortest_combination;
}*/

int main(){
    int n, m;
    while(cin>>n>>m){
        vector<int> a(m);
        for(int i = 0; i<m; i++){
            cin>>a[i];
        }
        map<int, vector<int>>memo;
        vector<int> result = bestsum(n, a, memo);
        cout<<"[ ";
        for(int i = 0; i<result.size(); i++){
            cout<<result[i]<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}