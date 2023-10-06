#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n, m;
    while(cin>>n>>m){
        vector<vector<int>> grid(n, vector<int>(m));
        bool flag = true;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin>>grid[i][j];
            }
        }
        
    }
    return 0;
}