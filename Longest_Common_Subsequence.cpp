#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string a, b;
int Lcs[1005][1005] = {0};
int LCS(int m, int n){
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i-1] == b[j-1]) Lcs[i][j] = Lcs[i-1][j-1]+1;
            else Lcs[i][j] = max(Lcs[i-1][j], Lcs[i][j-1]);
        }
    }
    //cout <<Lcs[m-1][n-1]<<endl;
    //cout << Lcs[m][n]<<endl;
    return Lcs[m][n];
}

int main(){
    while(getline(cin, a)){
        getline(cin, b);
        cout << LCS(a.size(), b.size()) <<endl;
    }
    return 0;
}

