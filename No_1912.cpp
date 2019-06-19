#include<iostream>
#include<algorithm>

using namespace std;

int arr[100001];

int main(){
  int input=0,i,j,Maxvalue=0,value=0;

  scanf("%d",&input);

  for(i=1;i<=input;i++){
    scanf("%d",&arr[i]);
  }

  value = arr[1];
  Maxvalue = value;
  for(i=2;i<=input;i++){
    value = max(arr[i],arr[i]+value);   // i번쨰와 i이전의 수들의 상태중 최고값을 찾는다.
    Maxvalue =max(Maxvalue,value);  //처음부터 i까지의 최고값을 찾는다.
  }

  printf("%d",Maxvalue);
  return 0;
}
