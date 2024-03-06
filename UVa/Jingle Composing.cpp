#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<char, double>memo = {
    {'W', 1},
    {'H', (double)1/(double)2},
    {'Q', (double)1/(double)4},
    {'E', (double)1/(double)8},
    {'S', (double)1/(double)16},
    {'T', (double)1/(double)32},
    {'X', (double)1/(double)64}
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    double diff = 1e-7;
    string s;
    while(cin>>s && s!="*"){
        int count = 0;
        double check = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '/'){
                if(fabs(1-check) < diff) count++;
                check=0;
            }else{
                check += memo[s[i]];
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}