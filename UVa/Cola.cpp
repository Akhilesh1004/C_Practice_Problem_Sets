#include <iostream>
#include <stdio.h>

using namespace std;



int main(){
    int n;
    int result;
    while(cin>>n){
        result = n;
        while(n >= 3){
            int free = n/3;
            result += free;
            n = free+n%3;
        }
        if(n==2) result++;
        cout<<result<<endl;
    }
    return 0;
}
