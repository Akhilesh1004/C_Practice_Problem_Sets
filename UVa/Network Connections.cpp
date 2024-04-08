#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void Union(int a, int b, vector<int>&dp, vector<int>&dp2){
    if(dp2[a] > dp2[b]){
        dp[b] = a;
    }else{
        dp[a] = b;
        if(dp2[a] == dp2[b]) dp2[b]++;
    }
}

int check(int a, vector<int>&dp){
    if(a != dp[a]){
        dp[a] = check(dp[a], dp);
    }
    return dp[a];
}

int main(){
    int t;
    cin>>t;
    for(int k = 0; k<t; k++){
        if(k) cout<<"\n";
        int n, a = 0, b = 0;
        cin>>n;
        vector<int>dp(n+1, 0), dp2(n+1, 0);
        for(int i = 0; i<=n; i++){
            dp[i] = i;
        }
        string s;
        cin.ignore();
        while(getline(cin, s) && s!=""){
            char c;
            int x, y;
            sscanf(s.c_str(), "%c %d %d", &c, &x, &y);
            int A = check(x, dp);
            int B = check(y, dp);
            switch(c){
                case 'c':
                    if(A!=B) Union(A, B, dp, dp2);
                    break;
                case 'q':
                    if(A==B) a++;
                    else b++;
            }
        }
        cout<<a<<","<<b<<"\n";
    }
    return 0;
}