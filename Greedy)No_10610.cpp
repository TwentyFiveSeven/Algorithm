#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> V;
int main(){
  int i,j,count=0,input=0,sum=0;
  char tmp=0;
  while(1){
    scanf("%c",&tmp);
    if(tmp == '\n') break;
    input = tmp-48;   //아스키코드 숫자 = -48, 대문자영어 = -64, 소문자영어 = -96
    V.push_back(input);
    sum +=input;      //더해서 3으로 나누어 떨어지면 3의배수.
    if(input ==0) count++;  //0이 포함돼 있다면 10의 배수.
  }
  if(count<1||sum%3!=0){    //3의 배수가 아니거나 10의 배수가 아니면 -1을 출력.
    printf("-1");
    return 0;
  }
  sort(V.begin(),V.end(),greater<int>()); //30의 배수이면 내림차순으로 정렬 후 출력.
  for(i=0;i<V.size();i++){
    printf("%d",V[i]);
  }
  return 0;
}
