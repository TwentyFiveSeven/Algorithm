#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> split(string s, char delimiter);
set<int> S;
bool cmp(string a,string b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    s = s.substr(1,s.size()-2);
    vector<string> val,V = split(s,'}');
    sort(V.begin(),V.end(),cmp);
    for(int i=0;i<V.size();i++){
        val = split(V[i],',');
        while(!val.empty()){
            int temp = atoi(val.back().c_str());
            val.pop_back();
            if(S.count(temp) == 0){
                S.insert(temp);
                answer.push_back(temp);
            }
        }
    }
    return answer;
}

vector<string> split(string s, char delimiter){
    vector<string> internal;
    stringstream ss(s);
    string temp;

    while (getline(ss, temp, delimiter)) {
        if(temp[0] == '{') temp = temp.substr(1,temp.size()-1);
        else if(temp[0] == ',') temp = temp.substr(2,temp.size()-2);
        internal.push_back(temp);
    }

    return internal;
}
