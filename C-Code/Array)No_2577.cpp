#include<iostream>
using namespace std;
int arr[10]={0,};
int main(){
  int a,b,c,mul=0,value = 0;
  scanf("%d %d %d",&a,&b,&c);
  mul = a*b*c;
  while(mul>0){
    value = mul%10;
    arr[value]+=1;
    mul /=10;
  }
  for(int i=0;i<10;i++){
    printf("%d\n",arr[i]);
  }
  return 0;
}
