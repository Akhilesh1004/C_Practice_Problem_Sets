#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>dp(n);
    for(int i = 0; i<n; i++) cin>>dp[i];
    int answer = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(dp[i]+j == dp[j]+i) answer++;
        }
    }
    cout<<answer<<"\n";
    return 0;
}