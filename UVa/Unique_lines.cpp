#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        for(int i = 0; i<n; i++){
            int x;
            cin>>x;
            vector<vector<int>>a(x, vector<int>(2));
            vector<vector<bool>>check(105, vector<bool>(105, false));
            for(int j = 0; j<x; j++){
                cin>>a[j][0]>>a[j][1];
            }
            int result = 0;
            for(int k = 0; k<x; k++){
                for(int y = k+1; y<x; y++){
                    
                }
            }
            cout<<result<<endl;
        }
    }
}