#include<iostream>
#include<math.h>
using namespace std;
int arr[1000];
int main(){
  int t,n;
  scanf("%d",&t);
  while(t--){
    int sum =0;
    double count =0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
      sum += arr[i];
    }
    sum /= n;
    for(int i=0;i<n;i++){
      if(arr[i] > sum)
        count +=1;
    }
    double value = (count/(double)n)*100;
    printf("%.3lf%%\n",round(value*1000)/1000);
  }
  return 0;
}
