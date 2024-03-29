#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int LIS(vector<int> dp){
    if(dp.empty()) return 0;
    vector<int>lis(dp.size(), 1);
    int len = 1;
    for(int i = 0; i<dp.size(); i++){
        for(int j= i+1; j<dp.size(); j++){
            if(dp[i]<dp[j]) lis[j] = max(lis[j], lis[i]+1);
        }
        if(lis[i]>len) len = lis[i];
    }
    return len;
}

vector<int>LIS_(vector<int>dp){
    if(dp.empty()) return {};
    vector<int>lis(dp.size(), 1);
    vector<int>prev(dp.size(), -1);
    int len = 1;
    int index = 0;
    for(int i = 0; i<dp.size(); i++){
        for(int j= i+1; j<dp.size(); j++){
            if(dp[j]>dp[i]){
                if(lis[i]+1 > lis[j]){
                    lis[j] = lis[i]+1;
                    prev[j]=i;
                }
            }
        }
        if(lis[i]>len){
            len = lis[i];
            index = i;
        }
    }
    vector<int> result(len);
    int x = len-1;
    while(index>=0){
        result[x--] = dp[index];
        index = prev[index];
    }
    return result;
}

void solve(int index, int len, vector<int>&temp, vector<vector<int>>&result, vector<int>dp, vector<int>lis){
    if(index == dp.size()) {
        if(temp.size() == len)result.push_back(temp);
        return;
    }
    if(temp.empty() || dp[index]>temp.back()){
        temp.push_back(dp[index]);
        solve(index+1, len, temp, result, dp, lis);
        temp.pop_back();
    }
    solve(index+1, len, temp, result, dp, lis);
}

vector<vector<int>> LIS_ALL(vector<int> dp){
    if(dp.empty()) return {{}};
    vector<int>lis(dp.size(), 1);
    int len = 1;
    for(int i = 0; i<dp.size(); i++){
        for(int j= i+1; j<dp.size(); j++){
            if(dp[i]<dp[j]) lis[j] = max(lis[j], lis[i]+1);
        }
        if(lis[i]>len) len = lis[i];
    }
    vector<vector<int>>result;
    vector<int>temp;
    solve(0, len, temp, result, dp, lis);
    return result;
}

int main(){
    int n;
    while(cin>>n){
        vector<int>dp(n);
        for(int i = 0; i<n; i++){
            cin>>dp[i];
        }
        /*
        cout<<LIS(dp)<<endl;
        vector<int> result = LIS_(dp);
        for(int x : result){
            cout<<x<<" ";
        }
        cout<<endl;
        */
        vector<vector<int>> result_ = LIS_ALL(dp);
        cout<<result_.size()<<endl;
        for(vector<int> combine : result_){
            for(int x : combine){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}