#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

int n, i;

void solve(vector<int>&dp){
    for(int j = 0; j<n; j++){
        int temp = dp[j]+i;
        temp = int(sqrt(temp));
        if(temp*temp == dp[j]+i || dp[j] == 0){
            dp[j] = i;
            i++;
            solve(dp);
        }
    }
}

int main(){
    int x;
    while(cin>>x){
        while(x--){
            cin>>n;
            vector<int>dp(55, 0);
            dp[0] = 1;
            i = 2;
            solve(dp);
            cout<<i-1<<endl;
        }
    }
}