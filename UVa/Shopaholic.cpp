#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int x, int y){
    return (x>y);
}

int main(){
    int t;
    while(cin>>t){
        for(int i = 0; i<t; i++){
            int n, total = 0;
            cin>>n;
            vector<int>p(n);
            for(int j = 0; j<n; j++) cin>>p[j];
            sort(p.begin(), p.end(), compare);
            for(int i = 2; i<n; i+=3) total += p[i];
            cout<<total<<endl;
        }
    }
    return 0;
}