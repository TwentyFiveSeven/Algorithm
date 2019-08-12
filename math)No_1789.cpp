#include<iostream>
using namespace std;

int main(){
  long long int s,count=1;
  scanf("%lld",&s);
  while(s>=count){  //최대를 구하기위해서는 가장 작은수 =1 부터 탐색해야한다.
    s -= count++; //나머지값이 뺸값보다 낮으면 전으로 돌아가서 마지막수를 더한다.
  }
  printf("%lld",count-1);
  return 0;
}
