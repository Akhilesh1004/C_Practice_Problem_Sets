#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    long long int n, m;
    while(cin>>n>>m){
        cout<<abs(n-m)<<endl;
    }
    return 0;
}