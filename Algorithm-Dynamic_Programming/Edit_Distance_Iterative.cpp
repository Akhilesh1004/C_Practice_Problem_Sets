#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;
int insertion, deletion, substitution;

int editdistance(string a, string b){
    vector<vector<int>>dp(a.size()+1, vector<int>(b.size()+1));
    for(int i = 0; i<=a.size(); i++){
        for(int j = (i == 0?1:0); j<=b.size(); j++){
            int Min = 9e8;
            if(j>0 && i>0) Min = dp[i-1][j-1]+(a[i-1] == b[j-1]?0:substitution);
            if(i>0) Min = min(Min, dp[i-1][j]+deletion);
            if(j>0) Min = min(Min, dp[i][j-1]+insertion);
            dp[i][j] = Min;
        }
    }
    return dp[a.size()][b.size()];
}

int main(){
    string a, b;
    while(cin>>a>>b){
        cin>>insertion>>deletion>>substitution;
        cout<<editdistance(a, b)<<endl;
    }
    return 0;
}