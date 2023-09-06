#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int LIS(int arr[], int m){
    int Lis[65536] = {[0 ... 65535] = 1};
    for(int i = 0; i < m; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]) Lis[i] = max(Lis[i], 1+Lis[j]);
        }
    }
    int l = 1;
    for(int z = 0; z < m; z++){
        l = max(Lis[z], l);
    }
    return l;
}

int main(){
    int n;
    cin >> n;
    int dp[n];
    for(int i = 0; i < n; i++){
        cin >> dp[i];
    }
    int ans = LIS(dp, n);
    cout << ans << endl;
    return 0;
}