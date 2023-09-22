#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        vector<long long> d(1<<n);
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                cin >> dp[i][j];
                dp[j][i] = dp[i][j];
            }
        }
        for (int s = 0; s <= (1 << n) - 1; s++) {
            for (int i = 0; i < n; i++) {
                if (s >> i & 1) continue;
                for (int j = 0; j < n; j++) {
                    if (s >> j & 1) continue;
                    int t = s | (1 << i) | (1 << j);
                    d[t] = max(d[t], d[s] + dp[i][j]);
                }
            }
        }
        cout << d[(1 << n) - 1] << endl;
    }
    return 0;
}