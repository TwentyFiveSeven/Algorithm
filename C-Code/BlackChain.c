#include<stdio.h>

int main(){
  long long sum=0,tmp=0,count=0,input =0;
  scanf("%lld",&input);
  count=1;
  while(1){
    tmp=count+1;
    sum = count+tmp;
    for(int i = 0; i<count;i++){
      tmp=tmp*2;
      sum += tmp;
    }
    if(input<=sum){
      break;
    }else{
      count++;
    }
  }
  printf("%d",count);
return 0;
}
