#include<iostream>
#include<algorithm>
using namespace std;

int arr[11];
int ans[5];
int n,save;

int main(){
  int i,j,sum =0,maxp=0,save=0;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&arr[i]);
    if(i<=4)
      ans[i] = arr[i];
  }
  if(n==4){
    sum=0;
    for(i=1;i<=n;i++)
      sum +=arr[i];
    printf("%d",sum);
    return 0;
  }

  for(i=5;i<=n;i++){
    for(j=1;j<=4;j++){
      ans[j] *=arr[j+i-4];
      if(ans[j]>maxp){
        maxp = ans[j];
        save = j;
      }
    }
  }
  for(i=1;i<=n;i++){
    if(i<save||i>save+n-4){
      maxp +=arr[i];
    }
  }
  printf("%d",maxp);
  return 0;
}
