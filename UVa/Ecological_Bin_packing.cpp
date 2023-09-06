#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <string.h>


using namespace std;

int main(){
    int brown[3], green[3], clear[3], temp, min;
    string ans;
    while(scanf("%d %d %d %d %d %d %d %d %d", &brown[0], &green[0], &clear[0], &brown[1], &green[1], &clear[1], &brown[2], &green[2], &clear[2]) != EOF){
        min = INT_MAX;
        temp = green[0]+clear[0]+brown[1]+green[1]+brown[2]+clear[2];
        if(temp < min){
            ans = "BCG";
            min = temp;
        }
        temp = green[0]+clear[0]+brown[1]+clear[1]+brown[2]+green[2];
        if(temp < min){
            ans = "BGC";
            min = temp;
        }
        temp = green[0]+brown[0]+green[1]+clear[1]+brown[2]+clear[2];
        if(temp < min){
            ans = "CBG";
            min = temp;
        }
        temp = green[0]+brown[0]+brown[1]+clear[1]+clear[2]+green[2];
        if(temp < min){
            ans = "CGB";
            min = temp;
        }
        temp = brown[0]+clear[0]+green[1]+clear[1]+brown[2]+green[2];
        if(temp < min){
            ans = "GBC";
            min = temp;
        } 
        temp = brown[0]+clear[0]+brown[1]+green[1]+clear[2]+green[2];
        if(temp < min){
            ans = "GCB";
            min = temp;
        }
        printf("%s %d\n", ans.c_str(), min);
    }
    return 0;
}