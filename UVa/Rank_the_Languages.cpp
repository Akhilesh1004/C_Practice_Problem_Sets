#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, a, b;

void dfs(int x, int y, vector<vector<char>>&dp, char c){
    if(x<0 || y<0 || x>=a || y>=b || dp[x][y] != c) return ;
    dp[x][y] = 0;
    for(int i = 0; i<4; i++){
        dfs(x+dx[i], y+dy[i], dp, c);
    }
}

int main(){
    while(cin>>n){
        for(int i = 1; i<=n; i++){
            cin>>a>>b;
            map<char, int>memo;
            vector<vector<char>>dp(a, vector<char>(b));
            for(int j = 0; j<a; j++){
                for(int k = 0; k<b; k++){
                    cin>>dp[j][k];
                }
            }
            int max = 0;
            for(int j = 0; j<a; j++){
                for(int k = 0; k<b; k++){
                    if(dp[j][k] == 0) continue;
                    char temp = dp[j][k];
                    int count = 0;
                    for(int x = 0; x<a; x++){
                        for(int y = 0; y<b; y++){
                            if(dp[x][y] == temp){
                                dfs(x, y, dp, temp);
                                count++;
                            }
                        }
                    }
                    memo[temp] = count;
                    if(count > max) max = count;
                }
            }
            cout<<"World #"<<i<<endl;
            for(int k = max; k>0; k--){
                for(char j = 'a'; j<='z'; j++){
                    if(memo.find(j) != memo.end() && memo[j]>=k){
                        cout<<j<<": "<<memo[j]<<endl;
                        memo[j] = 0;
                    }
                }
            }
        }
    }
    return 0;
}
