#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int travelling_salesman_problem(vector<vector<int>>dist, int start){
    vector<int>vertex;
    for(int i = 0; i<n; i++){
        if(i != start) vertex.push_back(i);
    }
    int min_path = INT_MAX;
    do{
        int current = 0, k = start;
        for(int i = 0; i<vertex.size(); i++){
            current += dist[k][vertex[i]];
            k = vertex[i];
        }
        current += dist[k][start];
        min_path = min(current, min_path);
    }while(next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

int main(){
    while(cin>>n>>m){
        vector<vector<int>>dist(n, vector<int>(n));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == j) dist[i][j] = 0;
                else cin>>dist[i][j];
            }
        }
        cout<<travelling_salesman_problem(dist, m)<<endl;
    }
    return 0;
}