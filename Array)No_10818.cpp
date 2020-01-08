#include<iostream>
using namespace std;

int main(){
  int n,min=1000001,max=-1000001,num;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&num);
    if(num>max)
      max = num;
    if(num<min)
      min = num;
  }
  printf("%d %d",min,max);
  return 0;
}
