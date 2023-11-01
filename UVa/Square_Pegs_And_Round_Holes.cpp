#include <iostream>
#include <stdio.h>

using namespace std;

int num[155];

int main(){
    int n;
    for(int i = 1; i<=150; i++){
        double r = i - 0.5;
        int sum = 0;
        for(int j = 1; j<i; j++){
            for(int k = 1; k<i; k++){
                if(j*j+k*k < r*r) sum++;
            }
        }
        num[i] = 4*sum;
    }
    while(cin>>n){
        int x, y;
        int d = 2*n-1;
        x = 8*n-4;
        y = num[n];
        cout<<"In the case n = "<<n<<", "<<x<<" cells contain segments of the circle."<<endl;
        cout<<"There are "<<y<<" cells completely contained in the circle."<<endl;
    }
    return 0;
}