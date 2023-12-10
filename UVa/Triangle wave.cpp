#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

void print(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<i; j++){
            cout<<i;
        }
        cout<<endl;
    }
    for(int i = n-1; i>=1; i--){
        for(int j = 0; j<i; j++){
            cout<<i;
        }
        cout<<endl;
    }
}

int main(){
    int n;
    while(cin>>n){
        for(int i = 0; i<n; i++){
            int a, f;
            cin>>a>>f;
            if(i) cout<<endl;
            for(int j = 0; j<f; j++){
                if(j) cout<<endl;
                print(a);
            }
        }
    }
}