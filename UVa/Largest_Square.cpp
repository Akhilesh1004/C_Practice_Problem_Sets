#include <iostream>
#include <stdio.h>

using namespace std;

char arr[100][100];
int n, height, width, nodes, a, b;

int isSquare(int r){
    int left, right, up, down;
    up = a - r;
    down = a + r;
    left = b - r;
    right = b + r;
    if(left < 0 || right >= width || up < 0 || down >= height) return 2*r-1;
    for(int j = up; j <= down; j++){
        if(arr[j][left] != arr[a][b]) return 2*r-1;
        if(arr[j][right] != arr[a][b]) return 2*r-1;
    }
    for(int i = left+1; i < right; i++){
        if(arr[up][i] != arr[a][b]) return 2*r-1;
        if(arr[down][i] != arr[a][b]) return 2*r-1;
    }
    return isSquare(r+1);
}

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d%d%d", &height, &width, &nodes);
        for(int x = 0; x < height; x++){
            for(int y = 0; y < width; y++){
                cin >> arr[x][y];
            }
        }
        printf("%d %d %d\n", height, width, nodes);
        while(nodes--){
            scanf("%d%d", &a, &b);
            printf("%d\n", isSquare(1));
        }
    }

    return 0;
}