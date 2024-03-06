#include <iostream>
#include <stdio.h>
#include <climits>

using namespace std;

int s, d, best_sur;
int month[13];

void dfs(int cur, int sur){
    if(cur>12){
        if(sur>best_sur){
            best_sur = sur;
        }
        return ;
    }
    int lastfive[6];
    for(int i = 1; i<=5; i++){
        if(cur-i>0){
            lastfive[i] = month[cur-i];
        }else{
            lastfive[i] = 0;
        }
    }
    int total = 0;
    for(int i = 1; i<=5; i++){
        total += lastfive[i];
    }
    if(cur>5 && total>0) return ;
    month[cur] = s;
    dfs(cur+1, sur+s);
    month[cur] = -d;
    dfs(cur+1, sur-d);
}

int main(){
    while(cin>>s>>d){
        for(int i = 0; i<13; i++){
            month[i] = 0;
        }
        best_sur = INT_MIN;
        dfs(1, 0);
        if(best_sur>=0) cout<<best_sur<<endl;
        else cout<<"Deficit"<<endl;
    }
    return 0;
}