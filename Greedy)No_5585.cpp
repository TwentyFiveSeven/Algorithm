#include<iostream>

using namespace std;

int money[7] ={0,500,100,50,10,5,1};

int main(){
  int payM=0,i,j,value =0,count=0;

  scanf("%d", &payM);
  payM = 1000-payM;
  for(i=1;i<=6;i++){
    value = payM/money[i];
    if(value>0){
      payM = payM - value*money[i];
      count += value;
    }
    if(payM==0) break;
  }
  printf("%d",count);

  return 0;
}
