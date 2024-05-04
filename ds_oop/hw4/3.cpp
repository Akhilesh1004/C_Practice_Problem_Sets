#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve(vector<int>dp, vector<int>dp2, vector<int>&result, int index, int x, int y){
    //cout<<result.size()<<"\n";
    if(x == y){
        result.push_back(dp2[x]);
        return ;
    }
    int i = 0;
    while(dp[index] != dp2[x+i]) i++;
    result.push_back(dp[index]);
    if(i == 0) solve(dp, dp2, result, index+i+1, x+i+1, y);
    else if(x+i == y) solve(dp, dp2, result, index+1, x, x+i-1);
    else{
        solve(dp, dp2, result, index+i+1, x+i+1, y);
        solve(dp, dp2, result, index+1, x, x+i-1);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n), dp2(n, 0);
    for(int i = 0; i<n; i++){
        cin>>dp[i];
        dp2[i] = dp[i];
    }
    sort(dp2.begin(), dp2.end());
    //for(int i = 0; i<n; i++) cout<<dp2[i]<<" ";
    //cout<<"\n";
    vector<int>result;
    solve(dp, dp2, result, 0, 0, n-1);
    cout<<result.back();
    result.pop_back();
    for(int i = result.size()-1; i>=0; i--) cout<<" "<<result[i];
    cout<<"\n";
    return 0;
}