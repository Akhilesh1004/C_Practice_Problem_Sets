#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
map<int, int>memo;

int solve(int n){
    if(memo.find(n) != memo.end()) return memo[n];
    if(n == 1) return 1;
    memo[n] = n*n+solve(n-1);
    return memo[n];
}

int main(){
    int n;
    while(cin>>n && n!=0){
        int result = solve(n);
        cout<<result<<endl;
    }
    return 0;
}