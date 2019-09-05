#include<iostream>
#include<map>
#include <string>
#include <vector>

using namespace std;
map<string,string> M;
vector<string> ans;
vector<char> S;
vector<string> solution(vector<string> record) {
    int i,j,count=0;
    vector<string> answer;
    for(i=0;i<record.size();i++){
         if(record[i].at(0) =='C'){
            string s,k;
            count =0;
            while(1){
                if(record[i].at(count) == ' '){
                    count++;
                    break;
                }
                count++;
            }
            while(1){
                if(record[i].at(count) == ' '){
                    count++;
                    break;
                }
                s += record[i].at(count++);
            }
            for(;count<record[i].size();count++){
                k += record[i].at(count);
            }
            int countM = M.count(s);
            if(countM>0){
                auto K = M.find(s);
                (*K).second = k;
            }
        }else if(record[i].at(0) == 'E'){
            S.push_back('E');
            string s,k;
            count =0;
            while(1){
                if(record[i].at(count) == ' '){
                    count++;
                    break;
                }
                count++;
            }
            while(1){
                if(record[i].at(count) == ' '){
                    count++;
                    break;
                }
                s += record[i].at(count++);
            }
            for(;count<record[i].size();count++){
                k += record[i].at(count);
            }
            ans.push_back(s);
            int countM = M.count(s);
            if(countM>0){
                auto K = M.find(s);
                (*K).second = k;
                continue;
            }
            M.insert(make_pair(s,k));
        }else{
             S.push_back('L');
             string s,k;
            count =0;
            while(1){
                if(record[i].at(count) == ' '){
                    count++;
                    break;
                }
                count++;
            }
            while(count!=record[i].size()){
                if(record[i].at(count) == ' '){
                    count++;
                    break;
                }
                s += record[i].at(count++);
            }
             ans.push_back(s);
         }
    }
    for(i=0; i<S.size();i++){
        auto K = M.find(ans[i]);
        string s = (*K).second;

        if(S[i] == 'E'){
            s +="님이 들어왔습니다.";
            answer.push_back(s);
            continue;
        }else{
            s +="님이 나갔습니다.";
            answer.push_back(s);
        }
    }
    return answer;
}
