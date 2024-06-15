#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int>dp){
    for(int i = 1; i<dp.size(); i++){
        if(dp[i-1]>dp[i]) return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n);
    for(int i = 0; i<n; i++) cin>>dp[i];
    int answer = 0;
    while(!check(dp)){
        for(int i = 0; i<n-1; i++){
            if(dp[i] > dp[i+1]){
                int temp = dp[i];
                dp[i] = dp[i+1];
                dp[i+1] = temp;
                answer++;
            }
        }
    }
    cout<<answer<<"\n";
    return 0;
}