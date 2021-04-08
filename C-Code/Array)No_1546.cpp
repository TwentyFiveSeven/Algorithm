#include<iostream>
using namespace std;

int main(){
  int n;
  double max = 0,sum=0,value = 0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%lf",&value);
    sum += value;
    if(value > max)
      max = value;
  }
  sum = ((sum/n)/max*100.00);
  printf("%lf",sum);
  return 0;
}
