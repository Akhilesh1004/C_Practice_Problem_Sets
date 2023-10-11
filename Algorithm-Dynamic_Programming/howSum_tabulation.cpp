#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
//O(nm^2) time, O(n^2) space
vector<int> howsum(int n, vector<int>&arrays){
    vector<vector<int>>table(n+1, vector<int>(n+1, -1));
    table[0] = {};
    for(int i = 0; i<=n; i++){
        for(int x : arrays){
            if(i+x<=n && (table[i].empty() || table[i][0] != -1)){
                table[i+x] = table[i];
                table[i+x].push_back(x);
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
        vector<int> result = howsum(n, a);
        if(result[0] == -1){
            cout<<"[]"<<endl;
            continue;
        }
        cout<<"[ ";
        for(int x : result){
            cout<<x<<" ";
        }
        cout<<"]"<<endl;

    }
    return 0;
}