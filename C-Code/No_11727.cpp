#include <iostream>
using namespace std;

int arr[1001];

int main(){
  arr[1]=1,arr[2]=3,arr[3]=5;
  int i,input,grid=1;

  scanf("%d",&input);

  for(i=4; i<=input;i++){
    grid = 1;
    if(i%2)
      grid = -1;
    arr[i] = (2*arr[i-1]+grid)%10007;
  }
  printf("%d",arr[input]);
  return 0;
}
