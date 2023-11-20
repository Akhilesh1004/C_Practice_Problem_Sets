#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


int main(){
    int n, x, y;
    while(cin>>n){
        while(n--){
            cin>>x>>y;
            vector<int>dp(4);
            for(int i = 0; i<x; i++){
                for(int j = 0; j<4; j++){
                    cin>>dp[j];
                }
                if(dp[0] == dp[2] && dp[1] == dp[3]) cout<<0<<endl;
                else if(abs(dp[0] - dp[2]) == abs(dp[1] - dp[3])) cout<<1<<endl;
                else if(abs(dp[0] - dp[2])%2 == abs(dp[1] - dp[3])%2) cout<<2<<endl;
                else cout<<"no move"<<endl;
            }
        }
    }
    return 0;
}