#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int LPS(string s, vector<vector<int>>&dp, int front, int back){
    if(back < front) return 0;
    if(front == back) return 1;
    if(dp[front][back] != -1) return dp[front][back];
    if(s[front] == s[back]){
        dp[front][back] = LPS(s, dp, front+1, back-1)+2;
        return dp[front][back];
    }
    dp[front][back] = max(LPS(s, dp, front+1, back), LPS(s, dp, front, back-1));
    return dp[front][back];
}

int main(){
    string n;
    while(cin>>n){
        vector<vector<int>>dp(n.size(), vector<int>(n.size(), -1));
        cout<<LPS(n, dp, 0, n.size()-1)<<endl;
    }
    return 0;
}