#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>dp(n);
    for(int i = 0; i<n; i++) cin>>dp[i];
    vector<int>result(n);
    for(int i = 0; i<n; i++){
        int j = i+1;
        while(dp[j] <= dp[i] && j<n) j++;
        if(j < n && dp[j] > dp[i]) result[i] = (j-i);
        else result[i] = 0;
    }
    cout<<result[0];
    for(int i = 1; i<n; i++) cout<<" "<<result[i];
    cout<<"\n";
    return 0;
}