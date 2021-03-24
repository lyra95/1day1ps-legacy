#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

struct Log{
    string name;
    string difficulty;
    string timelog;
    string url;
};


void createLog(){
    string name;
    string difficulty;
    string timelog;
    string url;

    cout << "enter name" << endl;
    cin >> name;

    cout << "enter difficulty" << endl;
    cin >> difficulty;

    cout << "enter time yyyymmdd (enter=default)" << endl;
    cin >> timelog;

    cout << "enter url" << endl;
    cin >> url;

    ofstream log{"log.txt"};
    log << "name " + name + '\n'
        << "difficulty " + difficulty + '\n'
        << "timelog " + timelog + '\n'
        << "url " + url;

    cout << "log.txt has created." << endl;
}


int main(){
    int n;
    cout << "0. exit\n"
             << "1. creat log.txt\n";
    while(cin>>n){
        if(n==1) createLog();
        if(n!=1) break;
        cout << "0. exit\n"
             << "1. creat log.txt\n";
    }  
}