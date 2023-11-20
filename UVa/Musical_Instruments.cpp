#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n, x;
    while(cin>>n){
        while(n--){
            int a, b;
            cin>>a>>b;
            vector<int>dp(a);
            for(int i = 0; i<b; i++){
                for(int j = 0; j<a; j++){
                    cin>>x;
                    if(x == 1) dp[j]++;
                }
            }
            int ans = 1;
            for(int i = 0; i<a; i++){
                if(dp[i]) ans *= dp[i];
            }
            cout<<ans<<endl;
        }
    }
}