#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

int main(){
    char name[100];
    char s[500], msg[201];
    ifstream fin;
    ofstream fout;
    cout<<"input your name: ";
    cin.getline(name, 99);
    do{
        cout<<endl;
        fin.open("/Users/ray/Desktop/C++_Practice_Problem_Sets/UVa/msg.txt");
        while(!fin.eof()){
            fin.getline(s, 200);
            cout<<s<<endl;
        }
        fin.close();
        cout<<name<<" : ";
        cin.getline(msg, 200);
        fout.open("/Users/ray/Desktop/C++_Practice_Problem_Sets/UVa/msg.txt", ios_base::app);
        if(strcmp(msg, "881") != 0){
            strcpy(s, name);
            strcat(s, ": ");
            strcat(s, msg);
            fout<<s<<endl;
        }
        fout.close();
    }while(strcmp(msg, "881") != 0);
    return 0;
}