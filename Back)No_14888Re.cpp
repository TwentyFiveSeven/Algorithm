#include<iostream>
using namespace std;
int n,Max = -1000000001,Min = 1000000001;
int arr[11],inqual[10],check[10];
void back(int depth,int value){
  if(depth == n){
    if(value > Max)
      Max = value;
    if(value< Min)
      Min = value;
    return;
  }
  for(int i=0;i<n-1;i++){
    if(!check[i]){
      check[i] = 1;
      int save = value;
      if(inqual[i] == 1) value+=arr[depth];
      else if(inqual[i] == 2) value -= arr[depth];
      else if(inqual[i] == 3) value *= arr[depth];
      else if(inqual[i] == 4) value /= arr[depth];
      back(depth+1,value);
      value = save;
      check[i] = 0;
    }
  }
}

int main(){
  int tmp1,tmp2,tmp3,tmp4,count = 0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  scanf("%d %d %d %d",&tmp1,&tmp2,&tmp3,&tmp4);
  while(tmp1--) inqual[count++] =1;
  while(tmp2--) inqual[count++] =2;
  while(tmp3--) inqual[count++] =3;
  while(tmp4--) inqual[count++] =4;
  back(1,arr[0]);
  printf("%d\n%d",Max,Min);
  return 0;
}
