#include <iostream>

using namespace std;

int arr[25][25], arr2[25][25];

int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>arr[i][j];
            if(i) arr[i][j] += arr[i-1][j];
        }
    }
    int temp, cur, m = -128*20*20;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            cur = 0;
            for(int k = 0; k<n; k++){
                if(i) temp = arr[j][k] - arr[i-1][k];
                else temp = arr[j][k];
                cur = max(temp, temp+cur);
                m = max(m, cur);
            }
        }
    }
    cout<<m<<"\n";
    return 0;
}