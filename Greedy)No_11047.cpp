#include<iostream>

using namespace std;

int arr[11];

int main(){
  int n=0,i,j,k=0,count=0,tmp=0;
  scanf("%d %d",&n,&k);
  for(i=1;i<=n;i++){
    scanf("%d",&arr[i]);
  }
  for(i=n;i>=1,k>0;i--){
    tmp = k/arr[i];
    if(tmp>0){
      k = k- tmp*arr[i];
      count+=tmp;
    }
  }
  printf("%d",count);
  return 0;
}
