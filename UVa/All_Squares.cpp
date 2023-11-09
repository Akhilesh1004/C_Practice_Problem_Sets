#include <iostream>
#include <stdio.h>

using namespace std;

int dx[4] = {1, -1, 1, -1};
int dy[4] = {1, 1, -1, -1};

int dfs(int k, int center_x, int center_y, int x, int y){
    int ans = 0;
    if(k){
        if(x >= center_x-k && x <= center_x+k && y >= center_y-k && y <= center_y+k){
            ans = 1;
        }
        for(int i = 0; i<4; i++){
            ans += dfs(k/2, center_x+k*dx[i], center_y+k*dy[i], x, y);
        }
    }
    return ans;
}

int main(){
    int x, y ,z;
    while(cin>>x>>y>>z && !(x==0 && y==0 && z== 0)){
        cout<<"  "<<dfs(x, 1024, 1024, y, z)<<endl;
    }
    return 0;
}