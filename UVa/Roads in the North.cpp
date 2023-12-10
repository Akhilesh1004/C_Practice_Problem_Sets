#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>

using namespace std;

int dfs(int from, int to, int &ans, vector<vector<pair<int, int>>>dp){
    int aroad = 0;
    int temp;
    for(int i = 0; i<dp[to].size(); i++){
        int go = dp[to][i].first;
        if(go != from){
            temp = dfs(to, go, ans, dp)+dp[to][i].second;
            ans = max(ans, temp+aroad);
            aroad = max(temp, aroad);
        } 
    }
    return aroad;
}

int main(){
    while(!cin.eof()){
        int x, y, z;
        string s;
        vector<vector<pair<int, int>>>dp(10001);
        vector<vector<int>>dp1(10001, vector<int>(10001, 0));
        int ans = 0;
        while(getline(cin, s) && s.size()>0 && !cin.eof()){
            stringstream ss;
            ss<<s;
            ss>>x>>y>>z;
            dp[x].push_back(make_pair(y, z));
            dp[y].push_back(make_pair(x, z));
        }
        dfs(0, 1, ans, dp);
        cout<<ans<<endl;
    }
    return 0;
}