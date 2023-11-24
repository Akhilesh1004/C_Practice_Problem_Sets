#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

int n, sz;

struct Node{
    string name;
    map<string, int>vis;
}node[40005];


void insert(string s){
    int len = s.size();
    s += '\\';
    string temp;
    int u = 0;
    for(int i = 0; i<=len; i++){
        temp = "";
        while(s[i] != '\\'){
            temp += s[i];
            i++;
        }
        if(!node[u].vis.count(temp)){
            node[sz].vis.clear();
            node[sz].name = temp;
            node[u].vis[temp] = sz;
            sz++;
        }
        u = node[u].vis[temp];
    }
}

void print(int u, int d){
    if(u){
        for(int i = 0; i<d; i++) cout<<" ";
        cout<<node[u].name<<endl;
    }
    for(map<string, int>::iterator it = node[u].vis.begin(); it != node[u].vis.end(); it++) print(it->second, d+1);
}

int main(){
    string s;
    while(cin>>n){
        sz = 1;
        node[0].vis.clear();
        for(int i = 0; i<n; i++){
            cin>>s;
            insert(s);
        }
        print(0, -1);
        cout<<endl;
    }
    return 0;
}