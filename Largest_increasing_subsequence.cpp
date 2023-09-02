#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int LIS(int arr[], int m){
    int Lis[65536] = {[0 ... 65535] = 1};
    for(int i = m-2; i >= 0; i--){
        for(int j = i+1; j < m; j++){
            if(arr[i] < arr[j]) Lis[i] = max(Lis[i], 1+Lis[j]);
        }
    }
    int max = 1;
    for(int z = 0; z < m; z++){
        if(Lis[z] > max) max = Lis[z];
    }
    return max;
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