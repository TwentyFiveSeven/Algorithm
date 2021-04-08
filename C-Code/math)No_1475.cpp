#include<iostream>
#include<algorithm>
using namespace std;
int arr[10];

int main(){
  int i,j,input=0,value;

  while(1){
    scanf("%c",&input);
    if(input =='\n') break;
    arr[input-48]++;
  }
  value = arr[6]+arr[9];
  if(value%2) value+=1;
  arr[6] = arr[9] = value/2;
  sort(arr,arr+10,greater<int>());
  printf("%d",arr[0]);
  return 0;
}
