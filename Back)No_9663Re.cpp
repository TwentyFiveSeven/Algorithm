#include<iostream>
using namespace std;
int arr[16];
int n,count=0;

int promising(int depth){
  for(int i=1;i<depth;i++){
    if(arr[i] == arr[depth]) return 0;
    if(arr[i]-arr[depth] == i-depth) return 0;
    if(arr[depth]-arr[i] == i-depth) return 0;
  }
  return 1;
}

void N_queens(int depth){
  if(depth == n+1){
    count++;
    return;
  }
  for(int i=1;i<=n;i++){
    arr[depth] = i;
    if(promising(depth)){
      N_queens(depth+1);
    }
  }
}

int main(){
  scanf("%d",&n);
  N_queens(1);
  printf("%d",count);
  return 0;
}
