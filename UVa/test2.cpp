#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

void wash(vector<int>&cp){
    int p1, p2, tmp;
    for(int i = 0; i<1000000; i++){
        p1 = rand()%52;
        p2 = rand()%52;
        if(p1 == p2) continue;
        tmp = cp[p1];
        cp[p1] = cp[p2];
        cp[p2] = tmp;
    }
}

void Sort(vector<int>&cp){
    for(int i = 0; i<13; i++){
        for(int j = i+1; j<13; j++){
            if(cp[i]>cp[j]){
                int tmp = cp[i];
                cp[i] = cp[j];
                cp[j] = tmp;
            }
        }
    }
}

bool compare(int x, int y){
    return (x%13 < y%13);
}

void print(int x){
    int f, d;
    f = x/13;
    d = x%13+1;
    switch(f){
        case 0:
            cout<<"S";
            break;
        case 1:
            cout<<"H";
            break;
        case 2:
            cout<<"D";
            break;
        default:
            cout<<"C";
            break;
    }
    switch(d){
        case 1:
            cout<<"A";
            break;
        case 11:
            cout<<"J";
            break;
        case 12:
            cout<<"Q";
            break;
        case 13:
            cout<<"K";
            break;
        default:
            cout<<d;
            break;
    }
    cout<<" ";
}

void print2(int x){
    int f, d;
    f = x/13;
    d = x%13+1;
    switch(d){
        case 1:
            cout<<"A";
            break;
        case 11:
            cout<<"J";
            break;
        case 12:
            cout<<"Q";
            break;
        case 13:
            cout<<"K";
            break;
        default:
            cout<<d;
            break;
    }
    switch(f){
        case 0:
            cout<<"S";
            break;
        case 1:
            cout<<"H";
            break;
        case 2:
            cout<<"D";
            break;
        default:
            cout<<"C";
            break;
    }
    cout<<" ";
}

int main(){
    srand(time(NULL));
    vector<int>cp(52);
    for(int i = 0; i<52; i++){
        cp[i] = i;
    }
    wash(cp);
    vector<vector<int>>c(4, vector<int>(13));
    for(int i = 0; i<13; i++){
        c[0][i] = cp[i];
    }
    sort(c[0].begin(), c[0].end());
    for(int i = 0; i<13; i++){
        print(c[0][i]);
    }
    cout<<endl;
    sort(c[0].begin(), c[0].end(), compare);
    for(int i = 0; i<13; i++){
        print(c[0][i]);
    }
    cout<<endl;
    for(int i = 0; i<13; i++){
        print2(c[0][i]);
    }
    cout<<endl;
    return 0;
}