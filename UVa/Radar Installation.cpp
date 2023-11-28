#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, double>&a, pair<double, double>&b){
    return a.first<b.first;
}

int main(){
    int x, y, index = 0;
    while(cin>>x>>y && x+y != 0){
        vector<pair<double, double>>dp;
        bool flag = true;
        int yy = y*y;
        for(int i = 0; i<x; i++){
            int a, b;
            cin>>a>>b;
            int xx = yy - b*b;
            if(xx < 0) flag = false;
            dp.push_back(make_pair(a+sqrt(xx), a-sqrt(xx)));
        }
        if(!flag){
            cout<<"Case "<<++index<<": "<<-1<<endl;
            continue;
        }
        sort(dp.begin(), dp.end(), compare);
        int ans = 0;
        double c = -1e9;
        for(pair<double, double> item : dp){
            if(item.second > c){
                c = item.first;
                ans++;
            }
        }
        cout<<"Case "<<++index<<": "<<ans<<endl;
    }
    return 0;
}