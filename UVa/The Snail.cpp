#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    double h, u, d, f;
    while(cin>>h>>u>>d>>f && h+u+d+f!=0){
        double dd = double(f)/100;
        double r = u*dd;
        double result = 0;
        int day = 0;
        while(result<=h){
            result += u;
            if(result > h){
                day++;
                break;
            }
            result -= d;
            if(result < 0){
                day++;
                break;
            }
            u -= r;
            if(u < 0) u = 0;
            day++;
        }
        if(result>h) cout<<"success on day "<<day<<endl;
        else cout<<"failure on day "<<day<<endl;
    }
    return 0;
}