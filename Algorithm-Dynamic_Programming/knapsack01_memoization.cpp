#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int knapsack01(int n, int m, vector<int>value, vector<int>weight){
    if(n<0 || value.empty() || weight.empty() || value.size() != weight.size()) return -1;
    if(n == 0 || m == 0) return 0;
    if(weight[m-1]>n) return knapsack01(n, m-1, value ,weight);
    else return max(value[m-1]+knapsack01(n-weight[m-1], m-1, value, weight), knapsack01(n, m-1, value, weight));

}

int main(){
    int n, m;
    while(cin>>n>>m){
        vector<int>value(m), weight(m);
        for(int i = 0; i<m; i++){
            cin>>weight[i]>>value[i];
        }
        cout<<knapsack01(n, m, value, weight)<<endl;
    }
    return 0;
}