#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;
long long int dp[INT16_MAX][INT16_MAX];
//O(mn) time, O(m+n) space;
//brute force O(2^n+m) time, O(n+m) space
long long int gridTraveler(int n, int m){
    if(m == 1 && n == 1) return 1;
    if(m ==0 || n == 0) return 0;
    if(dp[n][m]) return dp[n][m];
    else dp[n][m] = gridTraveler(n-1, m)+gridTraveler(n, m-1);
    return dp[n][m];
}

int main(){
    cout<<gridTraveler(1, 1)<<endl;
    cout<<gridTraveler(2, 3)<<endl;
    cout<<gridTraveler(0, 2)<<endl;
    cout<<gridTraveler(18, 18)<<endl;
    return 0;
}