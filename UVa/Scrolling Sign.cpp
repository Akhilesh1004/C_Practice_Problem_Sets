#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>


using namespace std;

int x, y;


void solve(string &s, vector<string> dp){
    s = dp[0];
    for(int i = 1; i<y; i++){
        for(int j = dp[i].size(); j>=0; j--){
            if(dp[i].substr(0, j) == s.substr(s.size()-j)){
                s += dp[i].substr(j);
                break;
            }
        }
    }
}


int main(){
    int n;
    string result;
    while(cin>>n){
        while(n--){
            cin>>x>>y;
            vector<string>dp(y);
            for(int i= 0; i<y; i++){
                cin>>dp[i];
            }
            result = "";
            solve(result, dp);
            cout<<result.size()<<endl;
        }
    }
    return 0;
}