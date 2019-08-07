#include<iostream>
using namespace std;

int arr[9] = {0,64,32,16,8,4,2,1,1};

int main(){
  int n,i,j,count=0,tmp=1;

  scanf("%d",&n);
  while(n<arr[tmp]) tmp++;
  while(n!=0){
    if(n/arr[tmp]>0){
      n = n - arr[tmp];
      count++;
    }else tmp++;
  }
  printf("%d",count);
  return 0;
}
