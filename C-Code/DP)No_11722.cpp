#include<iostream>

using namespace std;

int arr[1001],remb[1001];

int main(){
  int n,i,j,count=1,maxN=1;
  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d",&arr[i]);
    remb[i] = arr[i];
  }

  for(i=1;i<=n;i++){
    count =1;
    for(j=i+1;j<=n;j++){  // 현재 위치에서는 이전 것을 볼 필요가 없다.
      if(remb[i]>arr[j]){ //현재 기억하는 값보다 작으면 count+1;
        printf("i > j => remb[i] : %d, arr[j] : %d",remb[i],arr[j]);
        remb[i] = arr[j];
        count++;
        printf(" count : %d\n",count);
      }else if(remb[i]<arr[j]&&arr[i]>arr[j]){ //현재 기억하는 것 보다 크고 시작값보다 작다면 count=2로 다시 시작.
        printf("i < j => remb[i] : %d, arr[j] : %d",remb[i],arr[j]);
        remb[i] = arr[j];
        count = 2;
        printf(" count : %d\n",count);
      }
      if(count>maxN) maxN = count;
    }
  }
  printf("%d",maxN);
  return 0;
}
