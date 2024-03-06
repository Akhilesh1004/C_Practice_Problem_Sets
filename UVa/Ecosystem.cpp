#include <iostream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int arr[105][105], vis[105][105], route[105][105], res[105], n, ct;
map<vector<int>, int>memo;

void dfs(int s, int c, int d){
    if(d > 3){
        if(s == c){
            bool check = false, de = false, as = false;
            vector<int>temp = {res[2], res[0], res[1]};
            if(memo.count(temp)) check = true;
            temp = {res[1], res[2], res[0]};
            if(memo.count(temp)) check = true;
            for(int i = 1; i<3; i++){
                if(res[i-1] < res[i]) as = true;
                else de = true;
            }
            if(check || (de && as)) return ;
            cout<<res[0];
            route[res[n-1]][res[0]] = 1;
            for(int i = 1; i<3; i++){
                route[res[i-1]][res[i]] = 1;
                cout<<" "<<res[i];
            }
            cout<<"\n";
            ct++;
        }
        return ;
    }
    for(int i  = 1; i<=n; i++){
        if(c == i || vis[c][i]) continue;
        if(arr[c][i]){
            vis[c][i] = 1;
            res[d] = i;
            dfs(s, i, d+1);
            vis[c][i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n){
        ct = 0;
        memset(vis, 0, sizeof(vis));
        memset(route, 0, sizeof(route));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                cin>>arr[i][j];
            }
        }
        for(int i = 1; i<=n; i++){
            res[0] = i;
            dfs(i, i, 1);
        }
        cout<<"total:"<<ct<<"\n\n";
    }
    return 0;
}