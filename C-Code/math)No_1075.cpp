#include<iostream>
using namespace std;

int main(){
  int n,f,save=0;
  scanf("%d %d",&n,&f);
  save = n - n%100; //입력값에서 100을 나눈 나머지값을 빼준다.
  save = save%f == 0 ? save/f : (save/f)+1; //값이 떨어지면 몫+0, 안떨어지면 몫+1
  save = (save*f)%100;  //값을 곱한 다음 100으로 나눈 나머지값을 구한다.
  if(save/10>0){
    printf("%d",save);
  }else printf("0%d",save);
  return 0;
}
