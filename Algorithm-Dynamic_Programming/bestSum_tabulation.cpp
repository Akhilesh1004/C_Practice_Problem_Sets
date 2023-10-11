#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> bestsum(int n, vector<int>&arrays){
    vector<vector<int>> table(n+1, vector<int>(n+1, -1));
    vector<int>shortest_combination;
    table[0] = {};
    for(int i = 0; i<=n; i++){
        if(table[i].empty() || table[i][0] != -1){
            for(int x : arrays){
                if(i+x <= n){
                    shortest_combination = table[i];
                    shortest_combination.push_back(x);
                    if(table[i+x].empty() || table[i+x][0] == -1 || shortest_combination.size()<table[i+x].size()){
                        table[i+x] = shortest_combination;
                    }
                }
            }
        }
    }
    return table[n];
}

int main(){
    int n, m;
    while(cin>>n>>m){
        vector<int>a(m);
        for(int i = 0; i<m; i++){
            cin>>a[i];
        }
        vector<int> result = bestsum(n, a);
        cout<<"[ ";
        for(int x : result){
            cout<<x<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}