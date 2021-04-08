#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int prohibition[10];
int ans[7],countN=1,m,arr[7],countA,W,M;
int xi[2] = {1,-1};

void find(){
  int i,j,tmp=0;
  for(i=1;i<countN;i++){
    if(!prohibition[arr[i]]) {
      ans[i] =arr[i];
      countA++;
      continue;
    }
    for(j=1;j<=9;j++){
      tmp = arr[i] +xi[0]*j;
      if(tmp>=0&&tmp<=9&&!prohibition[tmp]){
        ans[i] = tmp;
        countA++;
        break;
      }
      tmp = arr[i] +xi[1]*j;
      if(tmp>=0&&tmp<=9&&!prohibition[tmp]){
        ans[i] = tmp;
        countA++;
        break;
      }
    }
  }
  for(i=1;i<countN;i++){
    W += ans[i];
    M += arr[i];
    // printf("%d %d\n",W,M);
    if(i==countN-1) break;
    W *=10;
    M *=10;
  }
  if(W<0){
    printf("%d",abs(M-100));
    return;
  }
  printf("%d",min(abs(M-100),countA+abs(W-M)));
  return;
}

int main(){
  int i,num;
  char input;
  while(1){
    scanf("%c",&input);
    if(input =='\n') break;
    arr[countN++] = input-48;
    // printf("input : %d, arr[i] : %d\n",input -48,arr[1]);
  }
  scanf("%d",&m);

  for(i=1;i<=m;i++){
    scanf("%d",&num);
    prohibition[num] = 1;
  }
  for(i=1;i<=6;i++) ans[i] = -1;
  find();
  return 0;
}
