#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int p;
    int z, s;
    double t = 100;
    for(int i = 1; i*4<=2000; i++){
        for(int j = i; i+j*3<=2000; j++){
            for(int k = j; i+j+k*2<=2000; k++){
                p = i*j*k;
                s = i+j+k;
                if(p <= 1000000 || (s*1000000)%(p-1000000)!=0) continue;
                z = (s*1000000)/(p-1000000);
                s += z;
                if(s > 2000 || z < k) continue;
                cout<<fixed<<setprecision(2)<<i/t<<" "<<j/t<<" "<<k/t<<" "<<z/t<<"\n";
            }
        }
    }
    return 0;
}