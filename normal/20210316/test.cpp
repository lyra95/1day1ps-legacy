#include "mySol.h"
#include "sol.h"
#include "sol2.h"
#include <iostream>
#include <string>
int main(){
    vector<int> t1 = {1,2,3,2,3};
    vector<int> a1 = {4,3,1,1,0};
    
    string r1 = (a1==mySol(t1)) ? "OK" : "failed";
    string r2 = (a1==sol1(t1)) ? "OK" : "failed";
    string r3 = (a1==sol2(t1)) ? "OK" : "failed";
    cout << "mySol "<< r1 << endl;
    cout << "sol "<< r2 << endl;
    cout << "sol2 "<< r3 << endl;
    return 0;
}