#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n, x;
    while(cin>>n){
        for(int i = 1; i<=n; i++){
            cin>>x;
            vector<int>a(x);
            for(int j = 0; j<x; j++){
                cin>>a[j];
            }
            int num = x/2;
            cout<<"Case "<<i<<": "<<a[num]<<endl;
        }
    }
    return 0;
}