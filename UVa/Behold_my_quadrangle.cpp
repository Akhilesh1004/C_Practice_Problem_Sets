#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        for(int i = 0; i<n; i++){
            vector<int>a(4);
            for(int j = 0; j<4; j++){
                cin>>a[j];
            }
            sort(a.begin(), a.end());
            if(a[0] == a[3]) cout<<"square"<<endl;
            else if(a[0] == a[1] && a[2] == a[3]) cout<<"rectangle"<<endl;
            else if(a[0]+a[1]+a[2]>a[3]) cout<<"quadrangle"<<endl;
            else cout<<"banana"<<endl;
        }
    }
    return 0;
}