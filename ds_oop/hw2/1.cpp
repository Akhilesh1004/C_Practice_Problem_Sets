#include <iostream> 
#include <vector> 
 
using namespace std; 
 
bool is_increasing(vector<int>&dp){ 
    for(int i = 1; i<dp.size(); i++){ 
        if(dp[i-1] > dp[i]) return false; 
    } 
    return true; 
} 
 
bool check(vector<int>&dp){ 
    for(int i = 0; i<dp.size(); i++){ 
        int temp = dp[i]; 
        if(i > 0) dp[i] = dp[i-1]; 
        else dp[i] = dp[i+1]; 
        if(is_increasing(dp)) return true; 
        dp[i] = temp; 
    } 
    return false; 
} 
 
int main(){ 
    int m; 
    cin>>m; 
    vector<int>dp(m); 
    for(int i = 0; i<m; i++) cin>>dp[i]; 
    if(is_increasing(dp) || check(dp)) cout<<"YES\n"; 
    else cout<<"NO\n"; 
    return 0; 
}  