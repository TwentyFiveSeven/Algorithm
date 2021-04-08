#include<iostream>
using namespace std;
int arr[1000001],n;
int main(){
  scanf("%d",&n);
  arr[1] = 0;arr[2] = 1;arr[3] = 1;
  for(int i=4;i<=n;i++){
    int Max = arr[i-1];
    if(!(i%3)&&arr[i/3] < Max) Max = arr[i/3];
    if(!(i%2)&&arr[i/2] < Max) Max = arr[i/2];
    arr[i] = Max+1;
  }
  printf("%d",arr[n]);
  return 0;
}
