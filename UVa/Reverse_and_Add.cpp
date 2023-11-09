#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int find_(vector<int>ans){
    int index = -1;
    for(int i = 9; i>=0; i--){
        if(ans[i] != 0){
            index = i;
            return index;
        }
    }
    return index;
}

bool check(vector<int>ans, int index){
    int x = index;
    for(int i  = 0; i<=index; i++){
        if(ans[i] != ans[x-i]) return false;
    }
    return true;
}

void addition(vector<int>a, vector<int>b, vector<int>&ans, int len){
    int carry = 0;
    for(int i = 0; i<10; i++){
        ans[i] = a[i]+b[i]+carry;
        if(ans[i] >= 10){
            ans[i] -= 10;
            carry = 1;
        }else{
            carry = 0;
        }
    }
}

void solve(vector<int>&a, vector<int>&b, vector<int>ans, int index){
    int x = index;
    for(int i = 0; i<=index; i++){
        a[i] = ans[i];
        b[x-i] = ans[i];
    }
}

int main(){
    int n, index, ir;
    while(cin>>n){
        for(int i = n; i>0; i--){
            vector<int>ans(10, 0), a(10, 0), b(10, 0);
            string x; 
            cin>>x;
            index = 0;
            ir = 1;
            for(int k = 0; k<x.size(); k++){
                a[k] = x[k] - '0';
                b[x.size() - k - 1] = x[k] - '0';
            }
            addition(a, b, ans, x.size());
            index = find_(ans);
            while(!check(ans, index)){
                solve(a, b, ans, index);
                addition(a, b, ans, index+1);
                index = find_(ans);
                ir++;
            }
            cout<<ir<<" ";
            for(int j = index; j>=0; j--){
                cout<<ans[j];
            }
            cout<<endl;
        }
    }
}