#include<iostream>
#include<algorithm>
using namespace std;

int arr[10];
int ans[8];

int main(){
  int i,j,sum=0,savef,saves,flag=0;
  for(i=1;i<=9;i++){
    scanf("%d",&arr[i]);
    sum+= arr[i];
  }

  for(i=1;i<=9;i++){
    for(j=i+1;j<=9;j++){
      if(sum-arr[i]-arr[j]== 100){
        arr[i]=101;   //값을 뻈을 때전체 합을 만들어 주는 첫번째 수를 100보다 큰수로 만든다.
        arr[j]=101;   //값을 뻈을 때전체 합을 만들어 주는 두번째 수를 100보다 큰수로 만든다.
        flag=1;
        break;
      }
    }
    if(flag==1)
      break;
  }
  sort(arr+1,arr+10); //정렬하면서 자연스럽게 제외 될 두개의 수는 출력 범위 밖으로 밀려난다.
  for(i=1;i<=7;i++){
    printf("%d\n",arr[i]);
  }

  return 0;
}
