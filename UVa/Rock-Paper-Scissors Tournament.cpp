#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int compare(string x, string y){
    if(y == x) return -1;
    if(y.size() > x.size()){
        if(x.size() == 4 && y.size() == 8) return 1;
        else return 0;
    }else{
        if(y.size() == 4 && x.size() == 8) return 0;
        else return 1;
    }
}

int main(){
    bool space = false;
    int n, k;
    while(cin>>n && n != 0){
        cin>>k;
        if(space) cout<<endl;
        space = true;
        double total = 0;
        vector<vector<int>>memo(n+1, vector<int>(2, 0));
        for(int i = 0; i<k*n*(n-1)/2; i++){
            int x, y;
            string s1, s2;
            cin>>x>>s1>>y>>s2;
            if(compare(s1, s2) == 1){
                memo[x][1]++;
                memo[y][0]++;
            }
            else if(compare(s1, s2) == 0){
                memo[y][1]++;
                memo[x][0]++;
            }
        }
        for(int i = 1; i<=n; i++){
            if(memo[i][1]+memo[i][0] != 0)cout<<fixed<<setprecision(3)<<double(memo[i][1])/double(memo[i][1] + memo[i][0])<<endl;
            else cout<<'-'<<endl;
        }
    }
    return 0;
}