#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int arr[100001];
int num[318];
//317
int main(){

  fill_n(arr,100001,100001);
  int i,j,n=0,count=1,tmp=0,k=0;
  scanf("%d",&n);

  k = (int)sqrt((double)n);

  for(i=1;i<=k;i++){
    num[i] = i*i;
  }

  for(i=1;i<=n;i++){
    if(i!=num[count]){            //제곱수가 아닐 때
      for(j=1;j<=count-1;j++){    //현재 위치에서 i보다 작은 제곱근들을 뺐을 때의 최소값을 구한다.
          tmp = i-num[j];
          arr[i] = min(arr[i],arr[tmp]);
      }
      arr[i] +=1; //가장 작은 값을 구한 후 +1 해준다.
    }else{
      count ++;
      arr[i] = 1;
    }
  }
  printf("%d",arr[n]);

  return 0;
}
