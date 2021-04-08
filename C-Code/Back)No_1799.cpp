#include<iostream>

using namespace std;

int R[20][2],L[20][2];  //대각선으로 최대 20x20으로 바둑판을 나눈다.
int n,arr[11][11],BQ[101],WQ[101],wm=1,bm=1,maxN; //BQ는 black의 위치를 저장 WQ는 white의 위치 저장.

int promising(int right, int left){
  if(R[right][1] || L[left][1])
    return 0;
  return 1;
}

void chess(int Q[],int count,int k,int m){
  int x,y,i,j,right,left;
  if(maxN<count)
    maxN = count;
  if(k==m)
    return;
  x = Q[k]/n;
  y = Q[k]%n+1;
  right = x+y-1;
  left = x-y+5;

  if(promising(right,left)){  //오른쪽 대각선, 왼쪽 대각선의 번호를 넘겨주어 해당 대각선들에 이미 바둑판이 있는지 확인.
    arr[x][y] = 2;  //유망하다면 2로 위치를 표시.
    R[right][1] = L[left][1] = 1; //현재 말의 우대각 좌대각에다가 말이 있음을 표시.
    chess(Q,count+1,k+1,m); // 현재 count+1 , k+1을 통해 다음 위치의 유망함을 확인한다.
    arr[x][y] = 1;
    R[right][1] = L[left][1] = 0;
    chess(Q,count,k+1,m); //현재 자리가 유망하지만, 현재 말을 두지않고 다음말을 두었을 떄를 확인.
  }
  else{
    chess(Q,count,k+1,m); //유망하지않을 때 다음말로 가기 위한 재귀
  }
}

int main(){
  int i,j,count=0,tmp=0,left,right,sum =0;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      scanf("%d",&tmp);
      arr[i][j] = tmp;
      if(tmp){
        if((i+j)%2){       //만약 말의 위치가 white(even)이면 WQ에 저장.
          WQ[wm++] = i*n+j-1;
        }else{    //만약 말의 위치가 black(odd)이면 BQ에 저장.
          BQ[bm++] = i*n+j-1;
        }
      }
    }
  }
  chess(WQ,0,1,wm); //white위에 있는 것을 먼저 탐색.
  sum = maxN;
  maxN =0;
  chess(BQ,0,1,bm); //다음 black에 있는 것을 먼저 탐색.
  sum += maxN;
  printf("%d",sum);

  return 0;
}
