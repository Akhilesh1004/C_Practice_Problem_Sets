#include <iostream>
#include <stdio.h>
#include <math.h>
#include <map>

using namespace std;

int main(){
    int n;
    map<int, int>memo;
    while(cin>>n){
        for(int i = 0; i<n; i++){
            long long int x;
            cin>>x;
            cout<<(x+1)*(x+1)-1<<endl;
        }
    }
    return 0;
}