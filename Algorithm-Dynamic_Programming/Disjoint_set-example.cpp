#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct node{
    int s;
    int n;
};

node boss[100000];

int find_root(int x){
    if(boss[x].s == x) return x;
    int root = find_root(boss[x].s);
    boss[x].n = (boss[x].n+boss[boss[x].s].n)%2;
    boss[x].s = root;
    return root;
}

void connect(int x, int y){
    int root_x = find_root(x);
    int root_y = find_root(y);
    boss[root_x].s = root_y;
    boss[root_x].n = (boss[y].n-boss[x].n+1)%2;
}

int main(){
    int n;
    for(int i = 0; i<100000; i++){
        boss[i].s = i;
        boss[i].n = 0;
    }
    while(cin>>n){
        for(int i = 0; i<n ;i++){
            int a, b;
            cin>>a>>b;
            for(int j = 0; j<b; j++){
                int x, y;
                char t;
                cin>>t>>x>>y;
                if(t == 'A'){
                    int root_x = find_root(x);
                    int root_y = find_root(y);
                    if(root_x != root_y) cout<<"Not sure"<<endl;
                    else if(boss[x].n == boss[y].n) cout<<"same"<<endl;
                    else cout<<"diff"<<endl;
                }else if(t == 'D'){
                    connect(x, y);
                }
            }
        }
    }
    return 0;
}