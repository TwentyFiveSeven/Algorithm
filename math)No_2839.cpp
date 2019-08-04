#include<iostream>
using namespace std;
int five[1001];

int main(){
  int i,j,n=0,div,value,ans;
  scanf("%d",&n);
  five[0] = 5;
  for(i=1;i<=1000;i++){
    five[i] = i*5;
  }
  div = n/5;  //가능한 5의 배수 중 가장 큰 수를 찾는다.
  for(i=div;i>=1;i--){
    value = n-five[i];  //값을 빼준다.
    if(!(value%3)){ //뺀 값이 3의 배수인지 확인.
      ans = value/3 + five[i]/5;
      printf("%d",ans);
      return 0;
    }
  }
  if(!(n%3)){
    printf("%d",n/3);
    return 0;
  }
  printf("-1");
  return 0;
}
