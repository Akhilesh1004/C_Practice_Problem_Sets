#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct Dice{
    int top = 1;
    int bottom = 6;
    int north = 2;
    int south = 5;
    int west = 3;
    int east = 4;

    void rotate(string c){
        int temp;
        if(c == "north"){
            temp = top;
            top = south;
            south = bottom;
            bottom = north;
            north = temp;
        }else if(c == "south"){
            temp = top;
            top = north;
            north = bottom;
            bottom = south;
            south = temp;
        }
        else if(c == "west"){
            temp = top;
            top = east;
            east = bottom;
            bottom = west;
            west = temp;
        }else{
            temp = top;
            top = west;
            west = bottom;
            bottom = east;
            east = temp;
        }
    }
};

int main(){
    int n;
    while(cin>>n && n!=0){
        Dice dice;
        for(int i = 0; i<n; i++){
            string s;
            cin>>s;
            dice.rotate(s);
        }
        cout<<dice.top<<endl;
    }
    return 0;
}