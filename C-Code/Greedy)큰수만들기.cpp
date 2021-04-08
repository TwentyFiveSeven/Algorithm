#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int limit,size;

string solution(string number, int k) {
    string answer="";
    size = number.size();
    limit = size - k;
    int save = -1;
    for(int i=0;i<limit;i++){
      char Max = '0'-1;
      int temp = -1;
      for(int j = save+1; j< k + i +1 ;j++ ){
        if(number[j] > Max){
          Max = number[j];
          temp = j;
        }
      }
      answer += Max;
      save = temp;
    }
    return answer;
}

int main(){
  string answer = solution("1231234",3);
  cout<<answer;
  return 0;
}
