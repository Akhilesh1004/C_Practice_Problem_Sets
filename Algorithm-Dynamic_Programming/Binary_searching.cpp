#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n, f;
    while(cin>>n>>f){
        vector<int>a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        int left = 0, right = a.size()-1;
        while(left<right){
            int mid = (left + right)/2;
            if(a[mid]<f){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        if(a[left] != f) cout<<false<<endl;
        else cout<<true<<" "<<left<<endl;
    }
    return 0;
}