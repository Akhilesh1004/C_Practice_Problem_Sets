#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

bool equal(double x, double y){
    return (abs(x-y) < 0.0001);
}

int main(){
    double x, y;
    while(cin>>x>>y && (x+y!=0)){
        if(x <= y) cout<<0<<endl;
        else if(x <= 2*y) cout<<1<<endl;
        else{
            if(0.5*x/y - int(0.5*x/y) == 0.5) cout<<0<<endl;
            else if(0.5*x/y - int(0.5*x/y) < 0.5) cout<<int(0.5*x/y)<<endl;
            else cout<<int(0.5*x/y)+1<<endl;
        }
    }
}