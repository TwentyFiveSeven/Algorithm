#include<iostream>
using namespace std;
const int MAX = 9;
int n,m;
int arr[MAX];
void func(int count){
  if(count == m){
    for(int i=0;i<m;i++)
      printf("%d ",arr[i]);
    printf("\n");
    return;
  }

  for(int i=1;i<=n;i++){
    if(count>0&&arr[count-1]>i)
      continue;
    arr[count] = i;
    func(count+1);
  }
}

int main(){
  scanf("%d %d",&n,&m);
  func(0);
  return 0;
}
