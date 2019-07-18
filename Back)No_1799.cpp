#include<iostream>

using namespace std;

int R[20][2],L[20][2];
int n,arr[11][11],Q[101],m=1,maxN;

int promising(int right, int left){
  if(R[right][1] || L[left][1])
    return 0;
  return 1;
}

void chess(int count,int k){
  int x,y,i,j,right,left;
  if(maxN<count)
    maxN = count;
  if(k==m)
    return;
  x = Q[k]/n;
  y = Q[k]%n+1;
  right = x+y-1;
  left = x-y+5;

  if(promising(right,left)){
    arr[x][y] = 2;
    printf("k : %d, i : %d, x : %d, y : %d ==> In !\n",k,i,x,y);
    R[right][1] = L[left][1] = 1;
    chess(count+1,k+1);
    if(R[right][0]<2&&L[left][0]<2)
      return;
    arr[x][y] = 1;
    R[right][1] = L[left][1] = 0;
    chess(count,k+1);
  }else{
    printf("k : %d, i : %d, x : %d, y : %d ==> Out !\n",k,i,x,y);
    chess(count,k+1);
  }
}

int main(){
  int i,j,count=0,tmp=0,left,right;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      scanf("%d",&tmp);
      arr[i][j] = tmp;
      if(tmp){
        Q[m++] = i*n+j-1;
        right = i+j-1;
        left = i-j+5;
        R[right][0]++;L[left][0]++;
      }
    }
  }
  chess(0,1);
  printf("%d",maxN);

  return 0;
}
