#include<iostream>
using namespace std;

int main(){
  int a,b,c,tmp=0,count=0;
  scanf("%d %d %d",&a,&b,&c);
  while((b-a)>1||(c-b)>1){  //a b c 사이에 숫자가 없을 떄 까지 진행.
    if(c-b>=b-a){
      tmp = a;
      a = b;
      b = c-1;
      // printf("%d %d %d\n",a,b,c);
      count++;
    }else{
      c = b;
      b= a+1;
      // printf("%d %d %d\n",a,b,c);
      count++;
    }
  }
  printf("%d",count);
  return 0;
}
