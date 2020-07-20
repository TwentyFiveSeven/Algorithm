#include <string>
#include <vector>
#include <iostream>
using namespace std;

void divideS(string &w,string &u, string &v){
    vector<char> V;
    int size = w.size(),left = 0, right = 0;
    if(w[0] == ')') right++;
    else left++;
    V.push_back(w[0]);
    u +=w[0];
    for(int i=1;i<size;i++){
        if(w[i] == ')')
            right++;
        else
            left++;
        u += w[i];
        if(i == 0)
            continue;
        if(right == left){
            if(i != size-1)
            v = w.substr(i+1,size-(i+1));
            break;
        }
    }
}

bool checkU(string u){
    vector<char> V;
    if(u[0]==')') return false;
    int size = u.size(),i=0;
    while(size--){
        if(u[i] =='(') V.push_back('(');
        else if(u[i] == ')'){
            if(V.back() == '(')
                V.pop_back();
            else
                V.push_back(')');
        }
        i++;
    }
    if(V.empty()) return true;
    else return false;
}

string recur(string w){
    if(w =="") return "";
    bool check = false;
    string ret = "";
    string u="",v="";
    divideS(w,u,v);
    check = checkU(u);
    if(check){
        ret = u + recur(v);
    }else{
        string newS = "(";
        newS += recur(v) + ")";
        u = u.substr(1,u.size()-2);
        for(int i=0;i<u.size();i++)
            if(u[i] == ')')
                u[i] = '(';
            else
                u[i] = ')';
        ret = newS + u;
    }
    return ret;
}
string solution(string p) {
    string answer = "";
    answer = recur(p);
    return answer;
}
