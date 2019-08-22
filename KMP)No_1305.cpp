#include<iostream>
#include<vector>
using namespace std;

int N,ans[1000001];
vector<char> arr;

void KMP(){
  int i=1,j=0;
  while(i<N){
    if(arr[i] == arr[j]){
      ans[i] = j+1;
      i++,j++;
    }else if(j>0){
      j = ans[j-1];
    }else{
      ans[i++] = 0;
    }
  }
}

int main(){
  int i,j;
  char temp;
  scanf("%d",&N);
  scanf("%c",&temp);
  for(i=0;i<N;i++){
    scanf("%c",&temp);
    arr.push_back(temp);
  }
  KMP();
  for(i=0;i<N;i++){
    printf("%d ",ans[i]);
  }
  printf("\n");
  printf("%d",N-ans[N-1]);
  return 0;
}
