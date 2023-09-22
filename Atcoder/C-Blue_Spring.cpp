#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

long long find_max(long long n, vector<long long> &dp, int pos){
    long long sum = 0;
    for(int i = 0; i<n; i++){
        if(pos<0) return sum;
        sum += dp[pos--];
    }
    return sum;
}

int main(){
    long long d, p, temp, sum;
    int n, count;
    while(scanf("%d %lld %lld", &n, &d, &p) != EOF){
        sum = 0;
        count = n-1;
        vector<long long> days(n, 0);
        for(int i = 0; i<n; i++){
            cin >> days[i];
        }
        sort(days.begin(), days.end());
        temp = find_max(d, days, count);
        while(temp >p){
            if(count < 0) break;
            count -= d;
            sum += p;
            temp = find_max(d, days, count);
        }
        if(count >= 0){
            for(int i = 0; i <= count; i++){
                sum += days[i];
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}