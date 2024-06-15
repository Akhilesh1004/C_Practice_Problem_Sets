#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    map<int, int>memo;
    bool answer = false;
    while(cin>>n){
        if(memo.find(n) != memo.end()){
            answer = true;
        }else{
            memo[n] = 1;
        }
    }
    if(answer) cout<<"true\n";
    else cout<<"false\n";
    return 0;
}