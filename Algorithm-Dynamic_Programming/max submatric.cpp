#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin>>n){
      vector<vector<int>> grid(n, vector<int>(n)), dp(n, vector<int>(n));
      for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
              cin >> grid[i][j];
              if(i==0) dp[i][j] = grid[i][j];
              else dp[i][j] = dp[i-1][j]+grid[i][j];
          }
      }
      int temp, m = INT_MIN, cur = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            cur = 0;
            for(int k = 0; k<n; k++){
                if(i == 0) temp = dp[j][k];
                else temp = dp[j][k]-dp[i-1][k];
                cur = max(temp, temp+cur);
                m = max(m, cur);
            }
        }
      }

      cout <<m<<"\n";

    }
    return 0;
}