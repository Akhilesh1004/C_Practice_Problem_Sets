#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    int dp[4][50], size[4] = {0};
    for(int i = 0; i < 10000; i++){
        for(int j = 0; j < 10000; j++){
            int length = 10;
            for(int k = 0; k < 4; k++, length*=10){
                if((i+j)*(i+j)==i*length+j && i/length == 0 && j/length == 0){
                    dp[k][size[k]++] = i*length + j;
                }
            }
        }
    }
    int n;
    while(scanf("%d", &n) != EOF){
        int index = n/2 - 1;
        for(int i = 0; i < size[index]; i++){
            printf("%0*d\n", n, dp[index][i]); 
        }
    }
    return 0;
}



