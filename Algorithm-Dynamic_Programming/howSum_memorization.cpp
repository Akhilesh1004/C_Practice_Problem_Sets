#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
/*
bool howsum(int n, vector<int>&arrays, vector<int>&result, map<int, bool>&memo){
    result.clear();
    if(n==0) return true;
    if(n<0) return false;
    if(memo.find(n)!=memo.end()) return memo[n];
    memo[n] = false;
    for(int x : arrays){
        if(howsum(n-x, arrays, result, memo)){
            result.push_back(x);
            memo[n] = true;
            return memo[n];
        }
    }
    return memo[n];
}

int main(){
    int n, m;
    while(cin>>n>>m){
        vector<int>a(m);
        for(int i =0 ;i<m;i++){
            cin>>a[i];
        }
        map<int, bool>memo;
        vector<int>result;
        howsum(n, a, result, memo);
        //cout<<result.size()<<endl;
        cout<<"[";
        for(int i = 0; i<result.size(); i++){
            cout<<result[i]<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
*/

vector<int> howsum(int n, vector<int>&arrays, map<int, vector<int>>&memo){
    if(n==0) return {};
    if(n<0) return {-1};
    if(memo.find(n)!=memo.end()) return memo[n];
    for(int x : arrays){
        int remainder = n-x;
        vector<int> remainder_combination= howsum(n-x, arrays, memo);
        if(remainder_combination.empty() || remainder_combination[0] != -1){
            remainder_combination.push_back(x);
            memo[n] = remainder_combination;
            return memo[n];
        }
    }
    memo[n] = {-1};
    return memo[n];
}

int main(){
    int n, m;
    while(cin>>n>>m){
        vector<int>a(m);
        for(int i =0 ;i<m;i++){
            cin>>a[i];
        }
        map<int, vector<int>>memo;
        vector<int> result = howsum(n, a, memo);
        //cout<<result.size()<<endl;
        cout<<"[ ";
        for(int i = 0; i<result.size(); i++){
            cout<<result[i]<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}