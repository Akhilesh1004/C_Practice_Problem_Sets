#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int r, c, n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin>>x;
    for(int t = 0; t<x; t++){
        if(t) cout<<"\n";
        cin>>r>>c>>n;
        vector<vector<char>>dp(r, vector<char>(c));
        for(int i  = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                cin>>dp[i][j];
            }
        }
        vector<vector<char>>temp = dp;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<r; j++){
                for(int k = 0; k<c; k++){
                    for(int z = 0; z<4; z++){
                        if(j+dx[z] < 0 || j+dx[z] >= r || k+dy[z] < 0 || k+dy[z] >= c) continue;
                        if(dp[j][k] == 'R' && dp[j+dx[z]][k+dy[z]] == 'S'){
                            temp[j+dx[z]][k+dy[z]] = 'R';
                        }
                        else if(dp[j][k] == 'P' && dp[j+dx[z]][k+dy[z]] == 'R'){
                            temp[j+dx[z]][k+dy[z]] = 'P';
                        }
                        else if(dp[j][k] == 'S' && dp[j+dx[z]][k+dy[z]] == 'P'){
                            temp[j+dx[z]][k+dy[z]] = 'S';
                        }
                    }
                }
            }
            dp = temp;
        }
        for(int i  = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                cout<<dp[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}