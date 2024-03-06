#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, index = 1;
    while(cin>>n){
        vector<int>dp(n);
        for(int i = 0; i<n; i++) cin>>dp[i];
        long long int m = 0;
        for(int i = 0; i<n; i++){
            long long int temp = 1;
            for(int j = i; j<n; j++){
                temp *= dp[j];
                m = max(m, temp);
            }
        }
        cout<<"Case #"<<index<<": The maximum product is "<<m<<".\n\n";
        index++;
    }
    return 0;
}