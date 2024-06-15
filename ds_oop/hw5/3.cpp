#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>dp, vector<int>&result, int x){
    if(result.size() == 6){
        cout<<result[0];
        for(int i = 1; i<6; i++){
            cout<<" "<<result[i];
        }
        cout<<"\n";
        return ;
    }
    for(int i = x; i<dp.size(); i++){
        result.push_back(dp[i]);
        dfs(dp, result, i+1);
        result.pop_back();
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n);
    for(int i = 0; i<n; i++) cin>>dp[i];
    vector<int>result;
    dfs(dp, result, 0);
    return 0;
}