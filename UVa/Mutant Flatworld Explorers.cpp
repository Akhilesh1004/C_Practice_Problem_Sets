#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y, r, c, index;
    char t;
    string s;
    cin>>x>>y;
    vector<vector<bool>> check(x+5, vector<bool>(y+5, false));
    while(cin>>r>>c>>t>>s){
        bool off = false;
        switch(t){
            case 'N':
                index = 0;
                break;
            case 'S':
                index = 2;
                break;
            case 'W':
                index = 3;
                break;
            case 'E':
                index = 1;
                break;
        }
        for(int i = 0; i<s.size(); i++){
            switch(s[i]){
                case 'L':
                    if(!off){
                        index -= 1;
                    }
                    break;
                case 'R':
                    if(!off){
                        index += 1;
                    }
                    break;
                case 'F':
                    if(!off){
                        if(!check[r][c] && (r+dx[index] > x || c+dy[index] > y || r+dx[index] < 0 || c+dy[index] < 0)){
                            off = true;
                            check[r][c] = true;
                        }
                        else if(check[r][c] && (r+dx[index] > x || c+dy[index] > y || r+dx[index] < 0 || c+dy[index] < 0)) {
                            break;
                        }
                        else {
                            r += dx[index];
                            c += dy[index];
                        }
                    }
                    break;
            }
            if(index < 0) index = 3;
            else if(index >=4 )index = 0;
            if(off) break;
        }
        switch(index){
            case 0:
                t = 'N';
                break;
            case 1:
                t = 'E';
                break;
            case 2:
                t = 'S';
                break;
            case 3:
                t = 'W';
                break;
        }
        cout<<r<<" "<<c<<" "<<t;
        if(off) cout<<" LOST\n";
        else cout<<"\n";
    }
    return 0;
}