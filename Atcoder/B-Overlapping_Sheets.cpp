#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;



int main(){
    int n, sum, x, y, w, h;
    while(scanf("%d", &n) != EOF){
        sum = 0;
        vector<vector<bool>> planes(150, vector<bool>(150, false));
        for(int i = 0; i<n; i++){
            scanf("%d %d %d %d", &x, &w, &y, &h);
            for(int j = x; j<w; j++){
                for(int k = y; k<h; k++){
                    if(!planes[j][k]){
                        planes[j][k] = true;
                        sum++;
                    }
                }
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}