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

int main(){
    string x, y;
    int index;
    while(cin>>x>>y){
        vector<int>a(maximun_bits, 0), b(maximun_bits, 0);
        index = 0;
        scan(x, a);
        scan(y, b);
        int carry = 0;
        vector<int>c(maximun_bits, 0);
        for(int i = 0; i<maximun_bits; i++){
            c[i] = a[i] - b[i];
            if(c[i] < 0){
                c[i] += 10;
                c[i+1]--;
            }
        }
        for(int i = maximun_bits-1; i>=0; i--){
            if(c[i] != 0){
                index = i;
                break;
            }
        }
        if(index == 0 && c[index]==0) cout<<0<<endl;
        else print(index, c);
    }
    return 0;

}