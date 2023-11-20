#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<int>dp(n);
        for(int i = 0; i<n; i++) cin>>dp[i];
        vector<bool>check(n, false);
        bool flag = true;
        for(int i = 0; i<n-1; i++){
            if(1 > abs(dp[i]-dp[i+1]) || abs(dp[i]-dp[i+1]) > n-1){
                flag = false;
                break;
            }else{
                check[abs(dp[i]-dp[i+1])] = true;
            }
        }
        for(int i = 1; i<n; i++){
            if(!check[i]) flag = false;
        }
        if(n == 1) cout<<"Jolly"<<endl;
        else if(flag) cout<<"Jolly"<<endl;
        else cout<<"Not jolly"<<endl;
    }
    return 0;
}