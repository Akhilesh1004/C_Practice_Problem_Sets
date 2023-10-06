#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;
long long int dp[INT16_MAX][INT16_MAX][1];

long long int gridTraveler(int n, int m){
    if(m == 1 && n == 1) return 1;
    if(m ==0 || n == 0) return 0;
    if(dp[n][m][0]) return dp[n][m][0];
    else dp[n][m][0] = gridTraveler(n-1, m)+gridTraveler(n, m-1);
    return dp[n][m][0];
}

int main(){
    cout<<gridTraveler(1, 1)<<endl;
    cout<<gridTraveler(2, 3)<<endl;
    cout<<gridTraveler(0, 2)<<endl;
    cout<<gridTraveler(18, 18)<<endl;
    return 0;
}