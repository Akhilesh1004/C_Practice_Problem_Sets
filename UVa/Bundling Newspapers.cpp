#include <iostream>
#include <vector>

using namespace std;

int len;
int res[30];
string dp[30];

void dfs(int d, int start, int end){
    if(d == end){
        for(int i = 0; i<end; i++){
            if(i)cout<<", ";
            cout<<dp[res[i]];
        }
        cout<<"\n";
        return ;
    }
    for(int i = start; i<len; i++){
        res[d] = i;
        dfs(d+1, i+1, end);
    }
}

int main(){
    int m;
    cin>>m;
    int a, b, p, q;
    getchar();
    getchar();
    for(int t = 0; t<m; t++){
        if(t)cout<<"\n";
        string op, s;
        getline(cin, op);
        len = 0;
        while(getline(cin, s) && s[0]!='\0'){
            dp[len] = s;
            len++;
        }
        int cnt = sscanf(op.c_str(), "%d%d", &a, &b);
        if(cnt == 0){
            p = 1;
            q = len+1;
        }else if(cnt == 1){
            p = a;
            q = a+1;
        }else if(cnt == 2){
            p = a;
            q = b+1;
        }
        for(int i = p; i<q; i++){
            if(i>p)cout<<"\n";
            cout<<"Size "<<i<<"\n";
            dfs(0, 0, i);
        }
        cout<<"\n";
    }
    return 0;
}