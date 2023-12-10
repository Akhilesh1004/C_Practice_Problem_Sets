#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int doom[13] = {-1, 10, 21, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12};
string week[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main(){
    int n;
    while(cin>>n){
        for(int i = 0; i<n; i++){
            int a, b;
            cin>>a>>b;
            int delta = (b - doom[a])%7;
            if(delta >= 0) cout<<week[delta]<<endl;
            else cout<<week[7+delta]<<endl;
        }
    }
    return 0;
}