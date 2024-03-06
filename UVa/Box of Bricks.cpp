#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>dp(n);
    for(int i = 0; i<n; i++) cin>>dp[i];
    int m = 50, index = 1;
    for(int i = 1; i<n-1; i++){
        if(m > max(dp[i-1], dp[i+1])){
            m = max(dp[i-1], dp[i+1]);
            index = i;
        }
    }
    cout<<index<<" "<<m<<"\n";
    return 0;
}