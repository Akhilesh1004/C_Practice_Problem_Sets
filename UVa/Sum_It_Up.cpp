#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

int t, n;

void solve(int i, int sum, vector<vector<int>>&result, vector<int>&temp, vector<int>dp, vector<bool>&check){
    if(sum == t){
        result.push_back(temp);
        return ;
    }
    if(i == n) return;
    int last = 0;
    for( ; i<dp.size(); i++){
        if(!check[i] && sum+dp[i]<=t){
            temp.push_back(dp[i]);
            check[i] = true;
            solve(i+1, sum+dp[i], result, temp, dp, check);
            temp.pop_back();
            check[i] = false;
        }
    }
}

int main(){
    while(cin>>t>>n && !(t==0 && n==0)){
        vector<int>dp(n);
        vector<bool>check(n, false);
        for(int i = 0; i<n; i++) cin>>dp[i];
        cout<<"Sums of "<<t<<":"<<endl;
        vector<vector<int>>result;
        vector<int>temp;
        solve(0, 0, result, temp, dp, check);
        set<vector<int>>s(result.begin(), result.end());
        result.assign(s.begin(), s.end());
        if(result.size() == 0) cout<<"NONE"<<endl;
        for(int j = result.size()-1; j>=0; j--){
            if(result[j].size() == 1) cout<<result[j][0]<<endl;
            else{
                for(int i = 0; i<result[j].size()-1; i++) cout<<result[j][i]<<"+";
                cout<<result[j].back()<<endl;
            }
        }
    }

}