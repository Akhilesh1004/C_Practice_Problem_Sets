#include <iostream>

using namespace std;

char arr[4][4];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        int sum = 0;
        for(int i = 0; i<4; i++){
            for(int j = 0; j<4; j++){
                cin>>arr[i][j];
                if(j==0 || j==2){
                    int temp = (arr[i][j]-'0')*2;
                    sum += temp/10;
                    sum += temp%10;
                }else{
                    sum += (arr[i][j]-'0');
                }
            }
        }
        if(sum%10 == 0) cout<<"Valid\n";
        else cout<<"Invalid\n";
    }
    return 0;
}
