#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    int a, b;
    while(cin>>a>>b && a!=0 && b!=0){
        int ans = sqrt(b) - sqrt(a) + 1;
        cout<<ans<<endl;
    }
    return 0;
}