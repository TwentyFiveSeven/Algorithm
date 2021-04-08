#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<char> V;
int solution(string s)
{
    for(int i=0;i<s.size();i++){
        if(!V.empty()&&s[i] == V.back()){
            V.pop_back();
        }else{
            V.push_back(s[i]);
        }
    }
    if(V.empty())
        return 1;
    return 0;
}
