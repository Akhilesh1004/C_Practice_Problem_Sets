#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void sort(int &a, int &b){
    if(a>b){
        int temp = a;
        a = b;
        b = temp;
    }
}

int main(){
    int n;
    
    vector<int>dict(105);
    int total = 0;
    for(int i = 0; i<=100; i++){
        if(i%2 != 0) total += i;
        dict[i] = total;
    }
    
    while(cin>>n){
        for(int i = 1; i<=n; i++){
            int a, b;
            cin>>a>>b;
            sort(a, b);
            /*
            int total = 0;
            for(int j = a; j<=b; j++){
                if(j%2 != 0) total += j;
            }
            cout<<"Case "<<i<<": "<<total<<endl;*/
            cout<<"Case "<<i<<": "<<dict[b] - dict[a-1]<<endl;
        }
    }
    return 0;
}