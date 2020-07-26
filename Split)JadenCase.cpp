#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

string solution(string s) {
    int count = 0;
    string answer = "",stream;
    istringstream ss(s);
    while(getline(ss, stream,' ')){
        count++;
        int size = stream.size();
        for(int i=0;i<size;i++){
            if(stream[i] >=65 && stream[i] <=90)
                stream[i] +=32;
        }
        if(stream[0]>=97 && stream[0] <= 122)
            stream[0] -= 32;
        answer += stream +' ';
    }
    if(s[s.size()-1] !=' ')
        answer = answer.substr(0,answer.size()-1);
    return answer;
}
