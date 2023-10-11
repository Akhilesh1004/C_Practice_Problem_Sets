#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <algorithm>

using namespace std;


struct Team{
    bool joined;
    int number;
    int problem_solved;
    int score;
    int error[10];
};

bool compare(Team a, Team b){
    if(a.problem_solved > b.problem_solved) return true;
    else if(a.problem_solved < b.problem_solved) return false;
    else if(a.score < b.score) return true;
    else if(a.score > b.score) return false;
    else if(a.number < b.number) return true;
    else return false;

}

int main(){
    int n;
    int contestant, problem, time;
    char L;
    string entry;
    stringstream ss;
    Team teams[101];
    while(cin>>n){
        getchar();
        getchar();
        for(int i = 0; i<n; i++){
            if(i)cout<<endl;
            for(int k = 0; k<=100; k++){
                teams[k].joined = false;
                teams[k].number = k;
                teams[k].problem_solved = 0;
                teams[k].score = 0;
                memset(teams[k].error, 0, sizeof(teams[k].error));
            }
            while(getline(cin, entry) && entry != ""){
                ss.clear();
                ss.str(entry);
                ss>>contestant>>problem>>time>>L;
                teams[contestant].joined = true;
                if(teams[contestant].error[problem] == -1) continue;
                if(L == 'C'){
                    teams[contestant].score += time+20*teams[contestant].error[problem];
                    teams[contestant].problem_solved++;
                    teams[contestant].error[problem] = -1;
                }
                else if(L == 'I'){
                    teams[contestant].error[problem]++;
                }
            }
            sort(teams, teams+101, compare);
            for(int j = 0; j<=100; j++){
                if(teams[j].joined){
                    cout<<teams[j].number<<" "<<teams[j].problem_solved<<" "<<teams[j].score<<endl;
                }
            }
        }

    }
    return 0;
}