#include <iostream>
#include <stdio.h>

using namespace std;

void compare(int *a, int *b){
    int temp;
    if(*a > *b){
        temp = *a;
        *a = *b;
        *b = temp;
    }
}
/*
int main(){
    int i, j, max, input, count;
    while(scanf("%d %d", &i, &j) != EOF){
        printf("%d %d ", i, j);
        compare(&i, &j);
        max = 0;
        while(i<=j){
            input = i;
            count = 1;
            while(input != 1){
                if(input % 2 != 0) input = 3*input +1;
                else input /= 2;
                count++;
            }
            if(count > max) max = count;
            i++;
        }
        printf("%d\n", max);
    }
    return 0;
}
*/

int main(){
    int i, j;
    while(cin>>i>>j){
        cout<<i<<" "<<j;
        compare(&i, &j);
        int max = 0;
        for(int n = i; n<=j; n++){
            int count = 1;
            int input = n;
            while(input != 1){
                if(input%2 != 0) input = input*3+1;
                else input /= 2;
                count++;
            }
            if(count > max) max = count;
        }
        cout<<" "<<max<<endl;
    }
    return 0;
}
