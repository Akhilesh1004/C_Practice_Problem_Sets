#include <iostream>
#include <vector>

using namespace std;

//n 0, e 1, s 2, w 3
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char o[4] = {'N', 'E', 'S', 'W'};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, h, w, x, y;
    int orientation = 0;
    cin>>n;
    while(n--){
        cin>>h>>w;
        cin.ignore();
        vector<string>dp(h);
        for(int i = 0; i<h; i++){
            getline(cin, dp[i]);
        }
        cin>>x>>y;
        x--;
        y--;
        char c;
        orientation = 0;
        while(cin>>c && c!='Q'){
            switch(c){
                case 'R':
                    orientation = (orientation+1)%4;
                    break;
                case 'L':
                    orientation = (orientation+3)%4;
                    break;
                case 'F':
                    if(dp[x+dx[orientation]][y+dy[orientation]] != '*' && x+dx[orientation] >=0 && x+dx[orientation] < h && y+dy[orientation] >= 0 && y+dy[orientation] < w){
                        x += dx[orientation];
                        y += dy[orientation];
                    }
                    break;
            }
        }
        cout<<x+1<<" "<<y+1<<" "<<o[orientation]<<"\n";
        if(n) cout<<"\n";
    }
    return 0;
}