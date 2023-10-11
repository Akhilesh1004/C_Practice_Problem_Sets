#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

//O(mn) time, O(mn) space;
long long int gridtraveler(int n, int m){
    vector<vector<long long int>> table(n+2, vector<long long int>(m+2, 0));
    table[1][1] = 1;
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            table[i+1][j] += table[i][j];
            table[i][j+1] += table[i][j];
        }
    }
    return table[n][m];
}

int main(){
    int n, m;
    while(cin>>n>>m){
        cout<<gridtraveler(n, m)<<endl;
    }
    return 0;
}