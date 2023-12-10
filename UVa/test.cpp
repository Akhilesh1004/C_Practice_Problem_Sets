#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

void update(int q[9][9][10], int r, int c, int n){
    for(int d = 1; d<10; d++){
        q[r][c][d] = 0;
    }
    for(int i = 0; i<9; i++){
        q[r][i][n] = 0;
        q[i][c][n] = 0;
    }
    for(int i = r/3*3; i<=r/3*3+2; i++){
        for(int j = c/3*3; j<=c/3*3+2; j++){
            q[i][j][n] = 0;
        }
    }
    q[r][c][n] = 1;
}

void read(int q[9][9][10]){
    ifstream fin;
    fin.open("/Users/ray/Desktop/C++_Practice_Problem_Sets/UVa/msg.txt");
    for(int i  =0 ; i<9; i++){
        for(int j = 0; j<9; j++){
            for(int k = 1; k<10; k++){
                q[i][j][k] = 1;
            }
        }
    }
    int n;
    for(int i  =0 ; i<9; i++){
        for(int j = 0; j<9; j++){
            fin>>n;
            q[i][j][0] = n;
            if(n>0){
                update(q, i, j, n);
            }
        }
    }
    fin.close();
}

void write(int q[9][9][10]){
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cout<<q[i][j][0]<<" ";
        }
        cout<<endl;
    }
}

int test(int q[9][9][10], int r, int c){
    int count = 0;
    int n;
    for(int i = 1; i<10; i++){
        if(q[r][c][i] == 1){
            count++;
            n = i;
        }
    }
    if(count==1){
        return n;
    }else{
        return 0;
    }
}

int main(){
    int q[9][9][10];
    int change;
    read(q);
    do{
        change = 0;
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(q[i][j][0] == 0){
                    int n = test(q, i, j);
                    if(n > 0){
                        change = 1;
                        q[i][j][0] = n;
                        update(q, i, j, n);
                    }
                }
            }
        }
    }while(change == 1);
    write(q);
    return 0;
}