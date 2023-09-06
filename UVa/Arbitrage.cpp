#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void printresult(vector<vector<vector<int>>> &paths, int t, int i, int j){
    if(t == 0){
        printf("%d %d", i+1, j+1);
        return;
    }
    printresult(paths, t-1, i, paths[t][i][j]);
    printf(" %d", j+1);
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        vector<vector<double>> conversiontable(n, vector<double>(n, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == j) conversiontable[i][j] = 1;
                else cin >> conversiontable[i][j];
            }
        }
        vector<vector<vector<double>>> values(n, vector<vector<double>>(n, vector<double>(n, 1)));
        vector<vector<vector<int>>> paths(n, vector<vector<int>>(n, vector<int>(n, -1)));
        values[0] = conversiontable;

        int item = -1, itemT = -1;
        for(int t = 1; t<n && item == -1; t++){
            for(int i = 0; i<n && item == -1; i++){
                for(int j = 0; j<n && item == -1; j++){
                    values[t][i][j] = -1;
                    for(int k = 0; k<n; k++){
                        double newrate = values[t-1][i][k]*conversiontable[k][j];
                        if(newrate > values[t][i][j]){
                            values[t][i][j] = newrate;
                            paths[t][i][j] = k;
                        }
                    }
                }
                if(values[t][i][i] > 1.01){
                    item = i;
                    itemT = t;
                    break;
                }
            }
        }
        if(item == -1){
            printf("no arbitrage sequence exists\n");
            continue;
        }
        printresult(paths, itemT, item, item);
        printf("\n");
    }
    return 0;
}