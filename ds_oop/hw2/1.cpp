#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, index = 0;
    cin>>n;
    vector<int>dp(n);
    for(int i = 0; i<n; i++){
        cin>>dp[i];
    }
    for(int i = 1; i<n; i++){
        if(dp[i-1] > dp[i]){
            dp[i-1] = dp[i];
            break;
        }
    }
    bool check = true;
    for(int i = 1; i<n; i++){
        if(dp[i-1] > dp[i]) check = false;
    }
    if(check)cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}