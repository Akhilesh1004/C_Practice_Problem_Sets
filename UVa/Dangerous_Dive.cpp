#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int main(){
    int x, y, a;
    while(cin>>x>>y){
        map<int, bool>dp;
        for(int i = 0; i<y; i++){
            cin>>a;
            dp[a] = true;
        }
        if(x == y) cout<<"*"<<endl;
        else{
            for(int i = 1; i<=x; i++){
                if(dp.find(i) == dp.end()){
                    cout<<i<<" ";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}