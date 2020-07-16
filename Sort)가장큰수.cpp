#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> hav;
int size = 0;

bool cmp(string a, string b){
    if(a+b > b+a)
        return true;
    else
        return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    int Zcheck= 0;
    size = numbers.size();
    for(int i=0;i<size;i++){
        hav.push_back(to_string(numbers[i]));
    }
    sort(hav.begin(),hav.end(),cmp);
    for(int i=0;i<size;i++){
        if(hav[i] != "0")
            Zcheck = 1;
        // cout<<hav[i]<<'\n';
        answer += hav[i];
    }
    if(!Zcheck) return "0";
    return answer;
}
