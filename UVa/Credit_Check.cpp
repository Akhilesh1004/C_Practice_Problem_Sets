#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int n, a[4];
    int result, x, y;
    while(cin>>n){
        for(int i = 0; i<n; i++){
            x = y = 0;
            cin>>a[0]>>a[1]>>a[2]>>a[3];
            for(int j = 0; j<4; j++){
                if((a[j]/10)%10*2 >= 10){
                    x += ((a[j]/10)%10*2)/10;
                    x += ((a[j]/10)%10*2)%10;
                }else{
                    x += ((a[j]/10)%10*2);
                }
                if((a[j]/1000)*2 >= 10){
                    x += ((a[j]/1000)*2)/10;
                    x += ((a[j]/1000)*2)%10;
                }else{
                    x += ((a[j]/1000)*2);
                }
                y += a[j]%10;
                y += (a[j]/100)%10;
            }
            result = x+y;
            if(result%10 == 0) cout<<"Valid"<<endl;
            else cout<<"Invalid"<<endl;
        }
    }
    return 0;
}