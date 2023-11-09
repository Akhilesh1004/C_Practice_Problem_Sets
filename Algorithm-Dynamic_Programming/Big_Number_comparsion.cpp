#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
//#include <bits/stdc++.h>

using namespace std;

const int maximun_bits = 100;

void scan(string input, vector<int>&output){
    int len = input.size()-1;
    for(int i = 0; i<input.size(); i++){
        output[len] = input[i]-'0';
        len--;
    }
}

void print(int index, vector<int>output){
    for(int i = index; i>=0; i--){
        cout<<output[i];
    }
    cout<<endl;
}

bool less_than(vector<int>a, vector<int>b){
    for(int i = maximun_bits-1; i>=0; i++){
        if(a[i] != b[i]) return a[i]<b[i];
    }
    return false;
}

bool more_than(vector<int>a, vector<int>b){
    for(int i = maximun_bits-1; i>=0; i++){
        if(a[i] != b[i]) return a[i]>b[i];
    }
    return false;
}

bool equal(vector<int>a, vector<int>b){
    for(int i = maximun_bits-1; i>=0; i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main(){
    string x, y;
    int index;
    while(cin>>x>>y){
        vector<int>a(maximun_bits, 0), b(maximun_bits, 0);
        index = maximun_bits;
        scan(x, a);
        scan(y, b);
        int carry = 0;
        vector<int>c(maximun_bits, 0);
        for(int i = 0; i<maximun_bits; i++){
            for(int j = 0; j<maximun_bits; j++){
                c[i+j] += a[i]*b[j];
                if(c[i+j] >= 10){
                    c[i+j+1] += c[i+j]/10;
                    c[i+j] %= 10;
                }
            }
        }
        for(int i = maximun_bits-1; i>=0; i--){
            if(c[i] != 0){
                index = i;
                break;
            }
        }
        print(index, c);
    }
    return 0;

}