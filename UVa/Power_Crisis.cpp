#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
/*
bool iswork(int n, int m){
    vector<bool> check(n+1, true);
    int temp = n-1;
    int x = 1;
    while(temp){
        if(x == 13) return false;
        if(check[x]){
            check[x] = false;
            temp--;
        }
        for(int i = 0; i<m; i++){
            if(x==n)x=0;
            if(!check[x+1])i--;
            x++;
        }
    }
    return true;
}

int main(){
    int n, ans;
    while(cin>>n){
        if(n == 0) break;
        int m = 1;
        while(1){
            if(iswork(n, m)) break;
            m++;
        }
        cout<<m<<endl;
    }
    return 0;
}
*/

//Josephus Problem

int main(){
    int n, m;
    while(cin>>n && n!=0){
        n--;
        for(m = 1; m<=n; m++){
            int turnoff = 0;
            for(int i = 1; i<=n; i++){
                turnoff = (turnoff+m)%i;
            }
            if(turnoff == 11) break;
        }
        cout<<m<<endl;
    }
}