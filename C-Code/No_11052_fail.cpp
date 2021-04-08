#include <iostream>
#include <algorithm>
using namespace std;

int Price[10001];
double Price_per[10001];
int sequence[10001];

void sort(int count){
  int i,j,tmp=0;
  double tmp1 =0.0;
  for(i=1;i<=count;i++){
    for(j=1;j<=count-1;j++){
      if(Price_per[j]<=Price_per[j+1]){
        tmp1 =Price_per[j];
        Price_per[j] = Price_per[j+1];
        Price_per[j+1]= tmp1;

        tmp = sequence[j];
        sequence[j]=sequence[j+1];
        sequence[j+1] = tmp;
      }
    }
  }
}

int main(){
  int i,input,order=1,sum=0,count=0,n=0,now=0;

  scanf("%d",&n);
  count = n;
  if(n>1000)
    n =1000;

  for(i=1; i<=count;i++){
    scanf("%d", &Price[i]);
    Price_per[i]=((double)Price[i])/(double)i;
    sequence[i] =i;
  }
  sort(count);
  while(now<n){
    if(now+sequence[order]<n){
      now += sequence[order];
      sum +=Price[sequence[order]];
    }else if(now+sequence[order]==n){
      now += sequence[order];
      sum +=Price[sequence[order]];
      break;
    }else{
      order++;
    }
  }
  printf("%d",sum);
}
