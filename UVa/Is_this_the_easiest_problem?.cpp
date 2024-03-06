#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a[3], n, index = 1;
    bool check;
    cin>>n;
    while(n--){
        cin>>a[0]>>a[1]>>a[2];
        cout<<"Case "<<index<<": ";
        if(a[0] > 0 && a[0]==a[1] && a[1]==a[2]){
            cout<<"Equilateral\n";
        }else if(a[0] > 0 && a[1] > 0 && a[2] > 0){
            check = true;
            if(a[0]>=a[1]+a[2]) check = false;
            else if(a[1]>=a[0]+a[2]) check = false;
            else if(a[2]>=a[0]+a[1]) check = false;
            if(check){
                if(a[0]==a[1]|| a[1]==a[2]|| a[0]==a[2]) cout<<"Isosceles\n";
                else cout<<"Scalene\n";
            }else{
                cout<<"Invalid\n";
            }
        }else{
            cout<<"Invalid\n";
        }
        index++;
    }
    return 0;
}