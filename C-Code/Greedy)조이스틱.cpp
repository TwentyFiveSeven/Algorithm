#include <string>
#include <vector>
#include <iostream>
using namespace std;

int calculate(int val){
    if(val-78 >=0)
        return 'Z'-val+1;
    else
        return val - 'A';
}

int solution(string name) {
    int answer=0,answer1 = 0,answer2 = 0,size = name.size(),save = 0,a,b;
    int Min = 2000000000;
    answer1 = calculate(name[0]);
    for(int i=1;i<size;i++){
        if(name[i] == 'A') save++;
        else{
            answer1 += calculate(name[i]) + save +1;
            save = 0;
        }
    }
    save = 0;
    int count = 0;
    a = b = size;
    while(a--){
        int i = count;
        answer2 = calculate(name[i])+count++;
        while(b--){
            i = i-1;
            if(i == count-1) break;
            if(i <0) i = size-1;
            if(name[i] == 'A')
                save++;
            else{
                answer2 += calculate(name[i])+save+1;
                save = 0;
            }
        }
        if(answer2 <= Min)
            Min = answer2;
        else
            break;
        b = size;
        save = 0;
    }
    answer = answer1;
    if(Min < answer1)
        answer = Min;
    return answer;
}
