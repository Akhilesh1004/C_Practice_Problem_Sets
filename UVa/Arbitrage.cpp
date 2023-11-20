#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int n;
int front[25][25][25];


void output(int t, int i, int s){
    if(t>=0){
        output(t-1, i, front[t][i][s]);
        cout<<" "<<s+1;
    }
    else{
        cout<<i+1;
    }
}

bool solve(vector<vector<vector<double>>>dp){
    for(int t = 1; t<n; t++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                for(int k = 0; k<n; k++){
                    if(dp[t][i][j] < dp[t-1][i][k]*dp[0][k][j]){
                        dp[t][i][j] = dp[t-1][i][k]*dp[0][k][j];
                        front[t][i][j] = k;
                    }
                }
            }
            if(dp[t][i][i]>1.01){
                output(t, i, i);
                cout<<endl;
                return true;
            }
        }
    }
    return false;
}

int main(){
    while(cin>>n){
        vector<vector<vector<double>>>dp(n, vector<vector<double>>(n, vector<double>(n, -1.0)));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == j) dp[0][i][j] = 1.0;
                else cin>>dp[0][i][j];
            }
        }
        if(!solve(dp)) cout<<"no arbitrage sequence exists"<<endl;
    }
    return 0;
}