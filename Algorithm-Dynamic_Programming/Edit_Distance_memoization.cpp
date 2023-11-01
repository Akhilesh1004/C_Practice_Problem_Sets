#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int insertion, deletion, substitution;

int editdistance(string a, string b, int n, int m, vector<vector<int>>&dp){
    if(a.size() == n && b.size() == m) return 0;
    if(a.size() == n) return insertion*(b.size() - m);
    if(b.size() == m) return deletion*(a.size() - n);
    if(dp[n][m] != -1) return dp[n][m];
    int x = editdistance(a, b, n+1, m+1, dp)+(a[n] == b[m]?0:substitution);
    int y = editdistance(a, b, n+1, m, dp)+deletion;
    int z = editdistance(a, b, n, m+1, dp)+insertion;
    dp[n][m] = min(x, min(y, z));
    return dp[n][m];
}

int main(){
    string a, b;
    while(cin>>a>>b){
        cin>>insertion>>deletion>>substitution;
        vector<vector<int>>dp(a.size(), vector<int>(b.size(), -1));
        cout<<editdistance(a, b, 0, 0, dp)<<endl;
    }
    return 0;
}