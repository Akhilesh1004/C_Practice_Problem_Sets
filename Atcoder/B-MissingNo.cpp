#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        vector<int>a(n);
        for(int i = 0; i<n; i++){
            scanf("%d", &a[i]);
        }
        sort(a.begin(), a.end());
        int result;
        bool check = false;
        for(int i = 0; i<n-1; i++){
            if((a[i+1]- a[i]) != 1){
                result = a[i]+1;
                check = true;
                break;
            }
        }
        if(!check) result = a[n-1]+1;
        printf("%d\n", result);
    }
    return 0;
}