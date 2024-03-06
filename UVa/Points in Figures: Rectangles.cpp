#include <iostream>

using namespace std;

double arr[15][4];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    char c;
    int index = 1;
    while(cin>>c && c != '*'){
        //x1, y2, x2, y1
        cin>>arr[index][0]>>arr[index][3]>>arr[index][2]>>arr[index][1];
        index++;
    }
    double x, y;
    int index1 = 1;
    while(cin>>x>>y && !(x==9999.9 && y==9999.9)){
        bool check = false;
        int result = 0;
        for(int i = 1; i<index; i++){
            if(x > arr[i][0] && x < arr[i][2] && y > arr[i][1] && y < arr[i][3]){
                cout<<"Point "<<index1<<" is contained in figure "<<i<<"\n";
                check = true;
            }
        }
        if(!check) cout<<"Point "<<index1<<" is not contained in any figure\n";
        index1++;
    }
    return 0;
}