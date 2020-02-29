#include<iostream>
using namespace std;
int arr[501];
int main(){
  int n,val = 0;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    arr[i] = arr[i-1];
    if(i%5 == 0){
      val = i;
      while(val%5 == 0){
        val /=5;
        arr[i]++;
      }
    }
  }
  printf("%d",arr[n]);
  return 0;
}
