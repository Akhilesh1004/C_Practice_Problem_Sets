#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long n, max_captured = 10;
    while(scanf("%lld", &n) != EOF){
        vector<long long>x(n);
        vector<long long>l(n);
        for(int i = 0; i<n; i++){
            cin >> x[i];
        }
        for(int i = 0; i<n; i++){
            cin >> l[i];
        }
        vector<long long> dp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp.push_back(x[i] - l[j]);
                dp.push_back(x[i] + l[j] +1);
            }
        }
        sort(dp.begin(), dp.end());
        max_captured = 0;
        
        for (int i = 0; i+1 < dp.size(); i++) {
            vector<long long> dis(n, 0);
            bool check = true;
            for(int j = 0; j<n; j++){
                dis[j] = abs(x[j] - dp[i]);
            }
            sort(dis.begin(), dis.end());
            for(int k = 0; k<n; k++){
                if(dis[k] > l[k]){
                    check = false;
                    break;
                }
            }
            if(!check) continue;
            else max_captured += dp[i+1] - dp[i];
        }
        printf("%lld\n", max_captured);
    }
    return 0;
}