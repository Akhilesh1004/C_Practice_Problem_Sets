#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

struct cell{
    double slope;
    int x;
    int y;
};

bool check(cell slope, vector<cell>slopes){
    cell x;
    double s;
    if(slopes.empty()) return true;
    for(int i = 0; i<slopes.size(); i++){
        x = slopes[i];
        if(x.slope == slope.slope){
            s = double(x.y - slope.y)/double(x.x - slope.x);
            if(s == x.slope) return false;
            if(x.x == slope.x && x.y == slope.y) return false;
        }
    }
    return true;
}

cell solve(pair<int, int> point1, pair<int, int> point2){
    if(point1.first == point2.first) return {9e6, point1.first, point1.second};
    else {
        double x = double(point2.second - point1.second) / double(point2.first - point1.first);
        return {x, point1.first, point1.second};
    }
}

int main(){
    int n;
    while(cin>>n){
        for(int i = 0; i<n; i++){
            int x;
            cin>>x;
            vector<vector<int>>a(x, vector<int>(2));
            for(int j = 0; j<x; j++){
                cin>>a[j][0]>>a[j][1];
            }
            vector<cell>slopes;
            for(int j = 0; j<x; j++){
                for(int k = j+1; k<x; k++){
                    cell slope = solve({a[j][0], a[j][1]}, {a[k][0], a[k][1]});
                    if(check(slope, slopes)) slopes.push_back(slope);
                }
            }
            cout<<slopes.size()<<endl;
        }
    }
}