#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

const int maxn = 100200;

int offset[5][2] = {
    {-1, 0}, {0, -1}, {1, -1}, {1, 0}, {0,1}
};

pair<int, int>maja[maxn+2000];

int main(){
    for(int i = 1, j = 1, k = 0; i<=maxn; i+=j, j+=6, k++){
        maja[i] = make_pair(0, k);
        for(int m  = 0; m<k; m++){
            maja[i-m] = make_pair(m, k-m);
        }
        int cur = i;
        for(int n = 0; n<5; n++){
            for(int m = 0; m<k; m++){
                int x = maja[cur].first + offset[n][0];
                int y = maja[cur].second + offset[n][1];
                maja[cur+1] = make_pair(x, y);
                cur++;
            }
        }
    }
    int ans;
    while(cin>>ans){
        cout<<maja[ans].first<<" "<<maja[ans].second<<endl;
    }
    return 0;
}