#include <iostream>
#include <stdio.h>

using namespace std;

int dp[6];

int main(){
    int n, cnt;
    while(cin>>n){
        bool flag = true;
        cnt = 0;
        if(n == 1){
            cout<<"Yes"<<endl;
            continue;
        }
        while(n/10 != 0){
            dp[++cnt] = n%10;
            n /= 10;
        }
        dp[++cnt] = n%10;
        
        for(int i = cnt-1; i>0; i--){
            if(dp[i+1] <= dp[i]) flag = false;
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}