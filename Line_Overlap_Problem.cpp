#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

int main(){
    stringstream ss;
    int dp[200000][2], n = 0;
    string input;
    int total = 0;
    while(getline(cin, input)){
        if(input == ".") break;
        ss.clear();
        ss << input;
        ss >> dp[n][0] >> dp[n][1];
        n++;
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j <= n; j++){
            if(dp[i][0] >= dp[j][0] && dp[i][1] <= dp[j][1]){
                total += (dp[i][1] - dp[i][0]);
            }
            else if(dp[i][0] <= dp[j][0] && dp[i][1] >= dp[j][1]){
                total += (dp[j][1] - dp[j][0]);
            }
            else if(dp[i][0] <= dp[j][1] && dp[i][0] >= dp[j][0]){
                total += (dp[j][1] - dp[i][0]);
            }else if(dp[j][0] <= dp[i][1] && dp[j][0] >= dp[i][0]){
                total += (dp[i][1] - dp[j][0]);
            }
        }
    }
    cout<<total<<endl;
    return 0;
}