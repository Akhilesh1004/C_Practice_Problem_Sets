#include <iostream>
#include <stdio.h>

using namespace std;

int f(int n){
    if(n/10 == 0) return n;
    int result = 0;
    while(n != 0){
        result += n%10;
        n /= 10;
    }
    return f(result);
}

int main(){
    int n;
    while(cin>>n && n != 0){
        cout<<f(n)<<endl;
    }
}