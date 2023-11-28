#include <iostream>
#include <stdio.h>

using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    int n;
    while(cin>>n && n != 0){
        int m = 1;
        while(m*m < n) m++;
        int x = min(m, n-(m-1)*(m-1));
        int y = min(m, m*m-n+1);
        if(m%2 != 0) swap(x, y);
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}