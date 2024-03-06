#include <iostream>

using namespace std;

int arr[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    cout<<"Lumberjacks:\n";
    while(n--){
        bool in = false, de = false;
        cin>>arr[0];
        for(int i = 1; i<10; i++){
            cin>>arr[i];
            if(arr[i] > arr[i-1]) in = true;
            else if(arr[i] < arr[i-1]) de = true;
        }
        if(in && de) cout<<"Unordered\n";
        else cout<<"Ordered\n";
    }
    return 0;
}