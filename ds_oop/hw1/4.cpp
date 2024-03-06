#include <iostream>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int arr[25][25] = {0};

int main(){
    int n;
    cin>>n;
    int index = 0, x = 0, y = 0, number = 1;
    while(number <= n*n){
        arr[x][y] = number;
        if(x+dx[index] >= n || y+dy[index] >= n || x+dx[index] < 0 || y+dy[index] < 0 || arr[x+dx[index]][y+dy[index]]!=0){
            index = (index+1)%4;
        }
        x += dx[index];
        y += dy[index];
        number++;
    }
    cout<<"[";
    for(int i = 0; i<n; i++){
        if(i)cout<<",";
        cout<<"[";
        for(int j = 0; j<n; j++){
            if(j) cout<<",";
            cout<<arr[i][j];
        }
        cout<<"]";
    }
    cout<<"]\n";
    return 0;
}