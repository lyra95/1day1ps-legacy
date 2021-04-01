#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

double sigmoid(double x){
    return 1.0/(1.0+exp(-x));
}

double expectation(double s,vector<double> & Q){
    double ans = 0.0;
    for(double & q:Q){
        ans += sigmoid(s-q);
    }
    return ans;
}

double findS(double a){
    double k = exp(6.0*a);
    double x = (1.0-k)/(-exp(3.0)+k*exp(-3.0));
    double ans = log(x);
    return ans;
}

double findQ(double a){
    return -findS(a);
}

double avg10000(const string & student){
    double ans = 0.0;
    for(char x:student){
        ans+= x-'0';
    }
    return ans/10000.0;
}
double avg100(const vector<string> & students, int j){
    double ans = 0.0;
    for(int i=0;i<100;i++){
        ans += students[i][j]-'0';
    }
    return ans/100.0;
}

void helper(){
    ifstream ifs{"input.txt"};
    vector<string> students(100);
    for(int i=0;i<100;i++){
        ifs >> students[i];
    }

    vector<double> S(100);
    vector<double> Q(10000);
    for(int i=0;i<100;i++){
        S[i] = findS(avg10000(students[i]));
    }
    for(int j=0;j<10000;j++){
        Q[j] = findQ(avg100(students,j));
    }

    int cheater = 0;
    double max = fabs(10000*avg10000(students[0])-expectation(S[0],Q));
    for(int i=1;i<100;i++){
        double temp = fabs(10000*avg10000(students[i])-expectation(S[i],Q));
        if(temp>max){
            cheater = i;
            max = temp;
        }
    }
    cout << cheater+1;
}

int main(){
    int t;
    cin >> t;
    int p;
    cin >> p;
    
    for(int i=0;i<t;i++){
        cout << "Case #" << i+1 << ": ";
        helper();
        cout << endl;
    }  
    return 0;
}