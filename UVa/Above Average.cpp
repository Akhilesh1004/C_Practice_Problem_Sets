#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while(cin>>n && !cin.eof()){
        for(int j = 0; j<n; j++){
            cin>>m;
            vector<double>stu(m);
            double total = 0;
            for(int i  = 0; i<m; i++){
                cin>>stu[i];
                total += stu[i];
            }
            double ave = total/m;
            int count = 0;
            for(int i = 0; i<m; i++){
                if(stu[i] > ave) count++;
            }
            cout<<fixed<<setprecision(3)<<((double)count/m)*100<<"%\n";
        }
    }
    return 0;
}