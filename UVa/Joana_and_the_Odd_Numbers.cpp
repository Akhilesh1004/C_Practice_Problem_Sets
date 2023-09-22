#include <iostream>
#include <stdio.h>

using namespace std;
long long int n, n1, n2 ,n3;

int main(){
    while(cin>>n){
        n = n/2+1;
        n = n*n;
        n1 = n*2-1;
        n2 = (n-1)*2-1;
        n3 = (n-2)*2-1;
        cout<<n1+n2+n3<<endl;
    }
    return 0;
}