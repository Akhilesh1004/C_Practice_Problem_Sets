#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n, m;
    while(cin>>n>>m){
        int total = n;
        int remain = 0;
        while(n/m != 0){
            total += n/m;
            remain = n/m;
            n %= m;
            n += remain;
        }
        cout<<total<<endl;
    }
    return 0;
}