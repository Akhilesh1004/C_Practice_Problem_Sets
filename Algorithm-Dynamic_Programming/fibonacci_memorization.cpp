#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;
map<int, long long int> memo;

long long int fib(int n){
    if(memo.find(n)!=memo.end()) return memo[n];
    if(n<=2) return 1;
    memo[n] = fib(n-1)+fib(n-2);
    return memo[n];
}

int main(){
    cout<<fib(7)<<endl;
    cout<<fib(50)<<endl;
    return 0;
}