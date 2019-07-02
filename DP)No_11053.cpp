#include<iostream>
#include<algorithm>

using namespace std;

int ans[1001];
int arr[1001];

int main(){
  int i,j,n=0,count=2,tmp=0,max = 0;

  scanf("%d", &n);

  for(i=1;i<=n;i++){
    scanf("%d",&arr[i]);
  }
   ans[1] = 1;

  for(i=2;i<=n;i++){
    max =0;
    for(j=1;j<i;j++){
      if(arr[j]<arr[i] && ans[j]>max){      //현재 값보다 작고, count의 수가 가장 많은 값을 찾는다.
        ans[i] = ans[j]+1;
        max = ans[j];
      }
    }
    if(ans[i]==0){
      ans[i] = 1;
    }
  }
sort(ans+1,ans+n+1,greater<int>());
printf("%d",ans[1]);
  return 0;
}
