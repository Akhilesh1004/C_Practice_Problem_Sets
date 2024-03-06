#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>dp(n);
    for(int i = 0; i<n; i++) cin>>dp[i];
    int count = 0;
    for(int i = 0; i<n; i++){
        int m = -1;
        for(int j = i+1; j<n; j++){
            if(dp[i] < m) break;
            else if(dp[j] < m) continue;
            else count++;
            m = max(m, dp[j]);
        }
    }
    cout<<count<<"\n";
    return 0;
}