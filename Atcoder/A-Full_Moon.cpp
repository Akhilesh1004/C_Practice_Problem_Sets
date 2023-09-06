#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int n, m, p;
    while(scanf("%d %d %d", &n, &m, &p) != EOF){
        if(n - m < 0) printf("0\n");
        else{
            printf("%d\n", (n-m)/p+1);
        }
    }
    return 0;
}