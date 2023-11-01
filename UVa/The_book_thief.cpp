#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;
int now;

int solve(long long int n){
    now = 0;
    while(n>0){
        now++;
        n -= now;
        if(n==0){
            now++;
            return n+now;
        }
    }
    return abs(n);
}

int main(){
    long long int n;
    while(cin>>n && n != 0){
        int result = solve(n);
        cout<<result<<" "<<now<<endl;
    }
    return 0;
}