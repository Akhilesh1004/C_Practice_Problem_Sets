#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int n ,goal;

void solve(int index, int current, vector<int>&mag, vector<bool>&selected){
    if(current == goal){
        for(int i = 0; i<n; i++){
            if(selected[i]) cout<<mag[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    if(index == n) return ;
    selected[index] = true;
    solve(index+1, current*mag[index], mag, selected);
    selected[index] = false;
    solve(index+1, current, mag, selected);
}

int main(){
    while(cin>>n>>goal){
        vector<int>mag(n);
        vector<bool>selected(n, false);
        for(int i = 0; i<n; i++) cin>>mag[i];
        solve(0, 1, mag, selected);
    }
    return 0;
}