#include<iostream>
using namespace std;

int arr[1001];

int main(){
  int input=0,i,j;

  scanf("%d",&input);

  arr[1]=1;
  arr[2]=2;
  for(i=3;i<=input;i++){
    arr[i]= (arr[i-2]+arr[i-1])%10007;  //현재 타일의 정렬방법은 i-1번쨰와 i-2번째의 영향을 받는다.
  }
  printf("%d",arr[input]);

  return 0;
}
