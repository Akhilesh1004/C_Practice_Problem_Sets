#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct cell{
    int x;
    int y;
    int index;
};

int main(){
    int n, a, b;
    while(cin>>n){
        while(n--){
            cin>>a>>b;
            int start_x, start_y, result;
            vector<vector<char>>dp(a, vector<char>(b));
            vector<vector<vector<bool>>>check(a, vector<vector<bool>>(b, vector<bool>(3, false)));
            for(int i = 0; i<a; i++){
                for(int j = 0; j<b; j++){
                    cin>>dp[i][j];
                    if(dp[i][j] == 'S'){
                        start_x = i;
                        start_y = j;
                    }
                }
            }
            queue<cell>q;
            cell start = {start_x, start_y, 0};
            check[start_x][start_y][0] = true;
            q.push(start);
            bool flag;
            cell next;
            result = -1;
            while(!q.empty()){
                cell cur = q.front();
                q.pop();
                int x1 = cur.x;
                int y1 = cur.y;
                if(dp[x1][y1] == 'E'){
                    result = cur.index;
                    break;
                }
                for(int i = 0; i<4; i++){
                    flag = true;
                    x1 = cur.x;
                    y1 = cur.y;
                    for(int j = cur.index%3; j>=0; j--){
                        x1 += dx[i];
                        y1 += dy[i];
                        if(x1<0 || y1<0 || x1>=a || y1>=b || dp[x1][y1] == '#'){
                            flag = false;
                            break;
                        }
                    }
                    if(flag && !check[x1][y1][(cur.index+1)%3]){
                        check[x1][y1][(cur.index+1)%3] = true;
                        next = {x1, y1, (cur.index+1)};
                        q.push(next);
                    }
                }
            }
            if(result == -1) cout<<"NO"<<endl;
            else cout<<result<<endl;
        }
    }
    return 0;
}