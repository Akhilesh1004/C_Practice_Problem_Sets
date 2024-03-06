#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    string s;
    int g = 34943;
    while(getline(cin, s) && s!="#"){
        long long int result = 0;
        for(int i = 0; i<s.size(); i++){
            result *= 256;
            result += s[i];
            result %= g;
        }
        int m2 = g - (result*256*256)%g;
        if(s.size() == 0) printf("00 00\n");
        else printf("%02X %02X\n", m2/256, m2%256);
    }
    return 0;
}