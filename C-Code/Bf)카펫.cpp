#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int size = yellow/2;
    for(int i=1;i<=yellow;i++){
        if(yellow%i == 0){
            int val = yellow/i;
            if((val+2)*2+i*2 == brown){
                answer.push_back(val+2);
                answer.push_back(i+2);
                break;
            }
        }
    }
    return answer;
}
