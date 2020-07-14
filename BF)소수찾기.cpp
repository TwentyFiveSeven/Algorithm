#include <string>
#include <set>
#include <math.h>
#include <iostream>
using namespace std;
int check[7];
set<int> V;
int size = 0;
string number = "";

void bf(int now,int depth, int limit,string s){
    if(depth == limit){
        V.insert(atoi(s.c_str()));
        return;
    }
    for(int i=0;i<size;i++){
        if(check[i] == 1) continue;
        check[i] =1;
        bf(i,depth+1,limit,s+number[i]);
        check[i] = 0;
    }
}

bool primeN(int val){
    if(val ==1 || val ==0) return false;
    for(int i=2;i<=sqrt(val);i++){
        if(val%i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    size = numbers.size();
    number = numbers;
    for(int i=1;i<=size;i++){
        bf(-1,0,i,"");
    }
    size = V.size();
    for(auto iter = V.begin(); iter != V.end(); iter++){
        if(primeN(*iter))
            answer++;
    }
    return answer;
}
