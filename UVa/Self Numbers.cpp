#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 1;
    map<int ,int>memo;
    while(n <= 1000000){
        int temp = n, temp2 = n;
        while(temp){
            temp2 += temp%10;
            temp /= 10;
        }
        memo[temp2] = 1;
        n++;
    }
    n = 1;
    while(n <= 1000000){
        if(!memo.count(n)) cout<<n<<"\n";
        n++;
    }
    return 0;
}