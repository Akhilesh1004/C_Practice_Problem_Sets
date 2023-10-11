#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
//O(nm) time, O(n) space
bool cansum(int n, vector<int>&arrays){
    vector<bool> table(n+1, false);
    table[0] = true;
    for(int i = 0; i<=n; i++){
        for(int x : arrays){
            if(i+x <= n && table[i]){
                table[i+x] = true;
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
        cout<<cansum(n, a)<<endl;
    }
    return 0;
}