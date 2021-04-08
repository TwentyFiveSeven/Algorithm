#include <string>
#include<iostream>
#include <vector>
#include <map>
using namespace std;
map<string,int> M;
    map<string,int> CHeck;
void Parser(string s){

    vector<string> ret;
    string k;
    int cut = 0;
    for(int i = 0;i != -1;){
        cut = s.find(" ",cut);
        if(cut == -1) {
            k = s.substr(i+1,s.size()-(i+1));
            if(i == 0)
                k = s.substr(i,s.size()-(i));
            if(M.count(k)){
                if(CHeck.count(k) == 0){
                    M[k]++;
                    CHeck.insert({k,1});
                }
            }else{
                M.insert({k,1});
                CHeck.insert({k,1});
            }
            break;
        }
        k = s.substr(i+1,cut-i-1);
        if(i == 0)
            k = s.substr(i,cut-i);
        if(M.count(k)){
            if(CHeck.count(k) == 0){
                M[k]++;
                CHeck.insert({k,1});
            }
        }else{
            M.insert({k,1});
            CHeck.insert({k,1});
        }
        i=cut;
        cut++;
        k="";
    }
    CHeck.clear();
}

int solution(vector<string> id_list, int k) {
    int answer = 0;
    vector<string> s;
    string coppy;
    int size = id_list.size();
    for(int i=0;i<size;i++){
        coppy = id_list[i];
        Parser(coppy);
    }
    for(auto iter = M.begin(); iter != M.end();iter++){
        if(iter->second > k) answer+=k;
        else
            answer+=iter->second;
    }
    return answer;
