#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    long long n ,sumz, ans;
    while(scanf("%lld", &n) != EOF){
        sumz = 0;
        ans = 9e18;
        vector<vector<long long int>> a(n+1, vector<long long>(3));
        for(int i = 1; i<=n; i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            sumz += a[i][2];
        }
        vector<long long> f(sumz+1, 9e18);
        f[0] = 0;
        for(int i = 1; i<=n; i++){
            long long w = max(0ll, (a[i][1]-a[i][0])/2 +1);
            for(int j = sumz; j>=a[i][2]; j--){
                f[j] = min(f[j], f[j-a[i][2]]+w);
            }
        }
        for(int i = (sumz/2+1); i<=sumz; i++){
            ans = min(ans, f[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}