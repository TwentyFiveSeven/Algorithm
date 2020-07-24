#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
map<string,vector<string>> M;
int count=0;
int solution(vector<vector<string>> clothes) {
    int answer = 1,Fsize = clothes.size();
    for(int i=0;i<Fsize;i++)
        M[clothes[i][1]].push_back(clothes[i][0]);
    int Msize = M.size();
    for(auto iter = M.begin();iter != M.end();iter++)
        answer = answer*((iter->second).size()+1);
    return answer-1;
}
