#include<iostream>
using namespace std;
const int MAX = 9;
int n,m;
int arr[MAX];
int visit[MAX];
void func(int count){
  if(count == m){
    for(int i=0;i<m;i++)
      printf("%d ",arr[i]);
    printf("\n");
    return;
  }

  for(int i=1;i<=n;i++){
    if(!visit[i]){
      visit[i] = 1;
      arr[count] = i;
      func(count+1);
      visit[i] = 0;
    }
  }
}

int main(){
  scanf("%d %d",&n,&m);
  func(0);
  return 0;
}
