/*
problem: https://programmers.co.kr/learn/courses/30/lessons/72410
objective: get used to <string> library.
tried to make the code easy for maintenance.
*/
#include <string>

using namespace std;
void inline check1(string & id){
    for(int i=0;i<id.size();i++){
        if(isupper(id[i])) id.replace(i,1,1,tolower(id[i])); 
    }
}
void inline check2(string & id){
    int i=0;
    while(i<id.size()){
        if(isalnum(id[i]) || id[i] =='-' || id[i]=='_' || id[i]=='.') i++;
        else id.erase(i,1);
    }
};
void inline check3(string & id){
    int i=1;
    while(i<id.size()){
        if(id[i]=='.' && id[i-1]=='.') id.erase(i,1);
        else i++;
    }
}
void inline check4(string & id){
    while(id.back()=='.') id.pop_back();
    while(id.front()=='.') id.erase(0,1);
}
void inline check5(string & id){
    if(id.size()==0) id += 'a';
}
void inline check6(string & id){
    if(id.size()>15){
        id.resize(15);
        check4(id);
    }
}
void inline check7(string & id){
    if(id.size()<3) id.resize(3,id.back());
}

string solution(string new_id) {
    check1(new_id);
    check2(new_id);
    check3(new_id);
    check4(new_id);
    check5(new_id);
    check6(new_id);
    check7(new_id);
    return new_id;
}