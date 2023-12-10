#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n, r;
    int index = 1;
    while(cin>>n>>r && (n+r) != 0){
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i = 0; i<r; i++){
            int x, y, z;
            cin>>x>>y>>z;
            dp[x][y] = z;
            dp[y][x] = z;
        }
        for(int k = 1; k<=n; k++){
            for(int i = 1; i<=n; i++){
                for(int j = 1; j<=n; j++){
                    dp[i][j] = max(dp[i][j], min(dp[i][k], dp[k][j]));
                }
            }
        }
        int s, t, d, carry;
        cin>>s>>t>>d;
        if(d%(dp[s][t]-1) > 0) carry = 1;
        else carry = 0;
        cout<<"Scenario #"<<index++<<endl;
        cout<<"Minimum Number of Trips = "<<(d/(dp[s][t]-1))+carry<<endl;
        cout<<endl;

    }
    return 0;
}