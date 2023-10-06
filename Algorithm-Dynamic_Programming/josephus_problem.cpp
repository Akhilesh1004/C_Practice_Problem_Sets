#include <iostream>
#include <stdio.h>

using namespace std;

int josephus(int n, int m){
    int p = 0;
    for(int i = 2; i<=n; i++){
        p = (p+m)%i;
    }
    return p+1;
}

int main(){
    cout<<josephus(11, 3)<<endl;
    return 0;
}
