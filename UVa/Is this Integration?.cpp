#include <iostream>
#include <stdio.h>
#include  <math.h>
#include <iomanip>

using namespace std;

int main(){
    double a;
    while(cin>>a){
        double x = (a*a - (a*a*M_PI/6 + a*sqrt(a*a-(a/2)*(a/2))/2));
        double y = (a*a - a*a*M_PI/4 - 2*x);
        double z = a*a - 4*x - 4*y;
        cout<<fixed<<setprecision(3)<<z<<" "<<4*y<<" "<<4*x<<endl;

    }
    return 0;
}