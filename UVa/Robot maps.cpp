#include <iostream>
#include <vector>

using namespace std;


int r, c;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int search(vector<vector<char>>dp, vector<vector<int>>&result, int x, int y){
    //int cur = ans;
    //if (x+dx[index] < 0 || x+dx[index] >= r || y+dy[index] < 0 || y+dy[index] >= c) return 0;
    //cout<<x<<" "<<y<<"\n";
    for(int i = 0; i<4; i++){
        if (x+dx[i] < 0 || x+dx[i] >= r || y+dy[i] < 0 || y+dy[i] >= c) {
            continue;
        }
        if(result[x+dx[i]][y+dy[i]] == -1) result[x+dx[i]][y+dy[i]] = 0;
    }
    for(int i = 0; i<4; i++){
        if (x+dx[i] < 0 || x+dx[i] >= r || y+dy[i] < 0 || y+dy[i] >= c) {
            continue;
        }
        if(dp[x+dx[i]][y+dy[i]] == '0' && result[x+dx[i]][y+dy[i]] != 1){
            result[x+dx[i]][y+dy[i]] = 1;
            return 1+search(dp, result, x+dx[i], y+dy[i]);
        }
    }
    return 0;
}

//-1 unvisited and invisible
//0 visible
//1 visited


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    while(cin>>r>>c && r+c != 0){
        cin>>x>>y;
        vector<vector<char>>dp(r, vector<char>(c));
        vector<vector<int>>result(r, vector<int>(c, -1));
        for(int i = 0 ;i<r; i++){
            for(int j = 0; j<c; j++){
                cin>>dp[i][j];
            }
        }
        result[x-1][y-1] = 1;
        int ans = search(dp, result, x-1, y-1);
        cout<<"\n|";
        for(int j = 0; j<c; j++){
            cout<<"---|";
        }
        cout<<"\n";
        for(int i = 0 ;i<r; i++){
            cout<<"|";
            for(int j = 0; j<c; j++){
                if(result[i][j] != -1) cout<<" "<<dp[i][j]<<" |";
                else cout<<" ? |";
            }
            cout<<"\n";
            cout<<"|";
            for(int j = 0; j<c; j++){
                cout<<"---|";
            }
            cout<<"\n";
        }
        cout<<"\nNUMBER OF MOVEMENTS: "<<ans<<"\n";
    }
    return 0;
}
