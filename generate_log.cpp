#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;

int main(){
    ofstream file("/Users/chengpingfeng/Desktop/C_Practice_Problem_Sets/log500.log", ios::app);
    if(!file.is_open()){
        cout<<"Error to open the file\n";
        return 0;
    }
    int c = 10000;
    while(c--){
        time_t now = time(nullptr);
        string timestr = asctime(gmtime(&now));
        timestr.erase(timestr.find_last_not_of(" \n\r\t")+1);
        string log = "127.0.0.1 - - ["+timestr+"] \"GET /index.html HTTP/1.1\" 500 1234\n";
        file<<log;
    }
    file.close();
    return 0;
}