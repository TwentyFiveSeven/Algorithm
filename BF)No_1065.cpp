#include<iostream>
using namespace std;

int main(){
  int i,j,n=0,one,two,three,count =99;
  scanf("%d",&n);
  if(n<=99){  //99 이전 까지는 n값과 같은 값을 가진다.
    printf("%d",n);
    return 0;
  }else if(n<=110){ //99~110 까지는 겹치는 수가 없기 때문에 99의 값을 갖는다.
    printf("99");
    return 0;
  }
  for(i=111;i<=n;i++){
    one = i/100;      //세번째 자리수
    two = (i-one*100)/10; // 두번째 자리수
    three = i%10; //첫번째 자리수
    if(two-one == three-two)// (두번째 자리수 - 첫번째 자리수) == (세번째 자리수 - 두번째 자리수) 가 성립하면 등차수열이다.
      count++;
  }

  printf("%d",count);

  return 0;
}
