#include <iostream>
#include <vector>

using namespace std;

int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};

char dp[10][10];

void check_(char c, bool *white, bool *black){
    if(islower(c)) *white = false;
    else *black = false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int d = 1;
    while(true){
        bool check = true, white = true, black = true;
        pair<int, int>wk, bk;
        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++){
                cin>>dp[i][j];
                if(dp[i][j] != '.') check = false;
            }
        }
        char king;
        if(check) break;
        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++){
                if(islower(dp[i][j])) king = 'K';
                else king = 'k';
                switch(dp[i][j]){
                    case 'p':
                        if( dp[i+1][j+1] == king ||
                            dp[i+1][j-1] == king )
                            white = false;
                        break;
                    case 'P':
                        if( dp[i-1][j+1] == king ||
                            dp[i-1][j-1] == king )
                            black = false;
                        break;
                    case 'n':
                    case 'N':
                        for(int k = 4; k<8; k++){
                            if( dp[i+dx[k]*2][j+dy[k]] == king || dp[i+dx[k]][j+dy[k]*2] == king )
                                check_(dp[i][j], &white, &black);
                        }
                        break;
                    case 'r': case 'q':
                    case 'R': case 'Q':
                        for(int k = 0; k<4; k++){
                            int step = 1;
                            while(dp[i+step*dx[k]][j+step*dy[k]] == '.' ) step++;
                            if( dp[i+step*dx[k]][j+step*dy[k]] == king )
                                check_(dp[i][j], &white, &black);
                        }
                        if( dp[i][j] == 'r' || dp[i][j] == 'R' ) break;
                    case 'b': case 'B':
                        for(int k = 4; k<8; k++){
                            int step = 1;
                            while(dp[i+step*dx[k]][j+step*dy[k]] == '.' ) step++;
                            if( dp[i+step*dx[k]][j+step*dy[k]] == king )
                                check_(dp[i][j], &white, &black);
                        }
                }  
                if(!black || !white) break;
            }
            if(!black || !white) break;
        }
        if(!black) cout<<"Game #"<<d<<": black king is in check.\n";
        else if(!white) cout<<"Game #"<<d<<": white king is in check.\n";
        else cout<<"Game #"<<d<<": no king is in check.\n";
        d++;
        //bk

    }
    return 0;
}