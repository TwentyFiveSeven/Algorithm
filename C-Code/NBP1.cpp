#include <string>
using namespace std;

int solution(string p) {
    int answer = 0,size = p.size();
    string temp;
    for(int i=0;i<size;i++){
        if(p[i] == '<'){
            temp = p.substr(0,i+1);
            if(temp.find('>')!= -1)
                continue;
            else
                answer++;
        }else{
            temp = p.substr(i,size-i);
            if(temp.find('<') != -1){
                continue;
            }else
                answer++;
        }
    }
    return answer;
}
