#include<iostream>
using namespace std;

int main(){
  int sum,i=0,ret,value;
  scanf("%d",&value);
  while(1){
    if((i+1)*(i+2)/2>=value)
      break;
    i++;
  }
  ret = i*(i+1)/2 +1;
  value = value - ret;
  if((i+1)%2){
    printf("%d/%d",(i+1)-(value),(1+value));
  }else{
    printf("%d/%d",(1+value),(i+1)-(value));
  }
  return 0;
}
