#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
//O(n) time, O(n) space
long long int fib(int n){
    vector<long long int> a(n+2, 0);
    for(int i = 0; i<n; i++){
        if(i == 1) a[i] = 1;
        a[i+1] += a[i];
        a[i+2] += a[i];
    }
    return a[n];
}

int main(){
    int n;
    while(cin>>n){
        cout<<fib(n)<<endl;
    }
    return 0;
}