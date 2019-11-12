#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 금 토 일 월 화 수 목
int month[12] = {3,1,3,2,3,2,3,3,2,3,2,3};
vector<string> day = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
string solution(int a, int b) {
    int value = 0;
    string answer = "";
    for(int i=0;i<a-1;i++)
        value += month[i];
    value += (b-1)%7;
    value %= 7;
    answer = day[value];
    return answer;
}
