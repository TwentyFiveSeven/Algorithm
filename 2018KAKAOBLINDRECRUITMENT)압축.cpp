#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
map<string,int> M;
vector<int> solution(string msg) {
    vector<int> answer;
    int size = 27;
    string temp ="";
    for(int i=0;i<26;i++){
        char c = 65+i;
        temp += c;
        M[temp] = i+1;
        temp ="";
    }
    temp = "";
    for(int i=0;i<msg.size();i++){
        temp +=msg[i];
        if(M.count(temp) == 1){
            if(i == msg.size()-1)
                answer.push_back(M[temp]);
            continue;
        }else{
            answer.push_back(M[temp.substr(0,temp.size()-1)]);
            M[temp] = size++;
            i--;
            temp = "";
        }
    }
    return answer;
}
