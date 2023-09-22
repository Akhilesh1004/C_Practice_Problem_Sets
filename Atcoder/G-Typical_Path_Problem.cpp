#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <limits.h>

const int N = 2e6+10;

using namespace std;

int dfc, total;
stack<int> s;
vector<int> g[N], G[N];
int n, m, a, b, c, u, v;
int f[N][22], fa[N], dfn[N], low[N], dep[N];


void Tarjan(int u, int fa){
    low[u] = dfn[u] = ++dfc;
    s.push(u);
    for(int v:g[u]){
        if(v == fa) continue;
        if(!dfn[v]){
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(dfn[u] <= low[v]){
                total++;
                int x;
                do{
                    x = s.top(); s.pop();
                    G[x].push_back(total);
                    G[total].push_back(x);
                }while(x != v);
                G[total].push_back(u);
                G[u].push_back(total);
            }
        }else{
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void dfs(int u, int pre){
    f[u][0] = fa[u] = pre;
    dep[u] = dep[pre]+1;
    for (int i = 1; i <= 21; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (auto v : G[u]) {
        if (v == pre) continue;
        dfs(v, u);
    }
}

vector<int> getpath(int x, int y){
    vector<int> path, tmp;
    while (dep[x] > dep[y]){
        path.push_back(x);
        x = fa[x];
    }
    while (dep[y] > dep[x]){
        tmp.push_back(y);
        y = fa[y];
    }
    while (x != y) {
        path.push_back(x),x = fa[x];
        tmp.push_back(y),y = fa[y];
    }
    path.push_back(x);
    while (!tmp.empty()) path.push_back(tmp.back()), tmp.pop_back();

    return path;
}

int main(){
    int T = 1;
    while(T--){
        scanf("%d %d", &n, &m);
        dfc = 0, total = n;
        scanf("%d %d %d", &a, &b, &c);
        for(int i = 0; i<m; i++){
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        Tarjan(1, 0);
        dfs(1, 0);
        vector<int> path = getpath(a, c);
        bool check = false;
        for(auto x: path){
            if(x == b) check = true;
            if(x > n){
                for(auto v: G[x]){
                    if(v == b){
                        check = true;
                    }
                }
            }
        }
        if(check){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}