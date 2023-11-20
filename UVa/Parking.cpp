#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n, x;
    while(cin>>n){
        while(n--){
            cin>>x;
            vector<int>dp(x);
            int min = 100, max = -1;
            for(int i = 0; i<x; i++){
                cin>>dp[i];
                if(dp[i] > max) max = dp[i];
                if(dp[i] < min) min = dp[i];
            }
            cout<<2*(max-min)<<endl;
        }
    }
    return 0;
}