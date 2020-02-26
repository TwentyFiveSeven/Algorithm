#include<iostream>
using namespace std;
int arr[10];
int main(){
  int n,k,sum=0,tmp;
  scanf("%d %d",&n,&k);
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  int i=n-1;
  while(k>0){
    tmp = k/arr[i];
    if(tmp>0){
      int temp = k/arr[i];
      sum += temp;
      k -= temp*arr[i];
    }
    i--;
  }
  printf("%d",sum);
  return 0;
}
