#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int gsd(int x, int y){
    int remain = x%y;
    if(remain == 0) return y;
    return gsd(y, remain);
}

void compare(int &a, int &b){
    if(a<b){
        int temp = a;
        a = b;
        b = temp;
    }
}

int main(){
    int n;
    while(cin>>n){
        for(int i = 0; i<n; i++){
            int x, y;
            cin>>x>>y;
            if(y%x != 0) cout<<-1<<endl;
            else{
                cout<<x<<" "<<y<<endl;
            }
        }
    }
    return 0;
}
