#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 1, 1, -1};
int dy[4] = {1, -1, 0, 1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin>>n){
        int index = 0;
        vector<int>result(2, 1);
        for(int i = 1; i<n;){
            if(index == 0 || index == 2){
                result[0] += dx[index];
                result[1] += dy[index];
                index = (index+1)%4;
                i++;
            }else if(result[0]+dx[index] >= 1 && result[1]+dy[index] >= 1){
                result[0] += dx[index];
                result[1] += dy[index];
                i++;
            }else{
                index = (index+1)%4;
            }
        }
        cout<<"TERM "<<n<<" IS ";
        cout<<result[0]<<"/"<<result[1]<<"\n";
    }
    return 0;
}