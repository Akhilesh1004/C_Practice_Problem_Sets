#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

long long solve(int n, map<long long, long long>&memo){
    if(n <= 1) return 1;
    if(memo.find(n) != memo.end()) return memo[n];
    memo[n] = solve(n-1, memo)+solve(n-2, memo);
    return memo[n];
}

int main(){
    int n;
    map<long long, long long>memo;
    while(cin>>n && n != 0){
        cout<<solve(n, memo)<<endl;
    }
    return 0;
}