#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int boss[10000000];

int find_root(int x){
    if(boss[x] == x) return x;
    int root = find_root(boss[x]);
    boss[x] = root;
    return root;
}

void connect(int x, int y){
    int root_x = find_root(x);
    int root_y = find_root(y);
    boss[root_x] = root_y;
}

int main(){
    for(int i = 0; i<10000000; i++) boss[i] = i;
    string n;
    int a, b;
    while(cin>>n>>a>>b){
        if(n == "connect"){
            connect(a, b);
        }else if(n == "check"){
            int root_a = find_root(a);
            int root_b = find_root(b);
            if(root_a == root_b) cout<<"True"<<endl;
            else cout<<"False"<<endl;
        }
    }
    return 0;
}