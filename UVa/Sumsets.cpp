#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

/*
int dp[1000];
int find(int n){
    for(int d = n-1; d >= 0; d--){
        for(int a = 0; a < n; a++){
            if(d==a) continue;
            int b = 0, c = n-1;
            while(b==a || b==d) b++;
            while(c==a || c==d) c--;
            while(b < c){
                int diff = dp[d] - (dp[a]+dp[b]+dp[c]);
                if(diff==0) return d;
                if(diff > 0){
                    b++;
                    while(b==a || b==d) b++;
                }else{
                    c--;
                    while(c==a || c==d) c--;
                }
            }
        }
    }
    return -1;
}
int main(){
    int n;
    while(scanf("%d", &n) && n){
        for(int i = 0; i < n; i++){
            scanf("%d", &dp[i]);
        }
        sort(dp, dp+n);
        int d = find(n);
        if(d != -1) printf("%d\n", dp[d]);
        else printf("no solution\n");
    }
    return 0;
}
*/

int solve(int n, vector<int>&dp){
    for(int d = n-1; d>=0; d--){
        for(int a = 0; a<n; a++){
            if(a == d) continue;
            int c = 0, b = n-1;
            while(c==d || c==a) c++;
            while(b==d || b==a) b--;
            while(c < b){
                int diff = dp[d] - (dp[a]+dp[b]+dp[c]);
                if(diff == 0) return d;
                else if(diff < 0){
                    b--;
                    while(b==d || b==a) b--;
                }
                else if(diff > 0){
                    c++;
                    while(c==d || c==a) c++;
                }
            }
        }
    }
    return -1;
}

bool compare(int &a, int &b){
    return a<b;
}

int main(){
    int n;
    while(cin>>n && n!=0){
        vector<int>dp(n);
        for(int i = 0; i<n; i++){
            cin>>dp[i];
        }
        sort(dp.begin(), dp.end(), compare);
        int result = solve(n, dp);
        if(result == -1) cout<<"no solution"<<endl;
        else cout<<dp[result]<<endl;
    }
    return 0;
}