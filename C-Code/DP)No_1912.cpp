#include<iostream>
#include<algorithm>
using namespace std;
int arr[100001],value,Maxvalue;
int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  value = Maxvalue = arr[0];
  for(int i=1;i<n;i++){
    value = max(arr[i],arr[i]+value);
    Maxvalue = max(Maxvalue,value);
  }
  printf("%d",Maxvalue);
  return 0;
}
