#include <iostream>
#include <stack>

using namespace std;

int **a;
int *v;
int n;

void visit(int i){
  int j;
  if(count !=0){
    v[i] =1;
  }
  for(j=1;j<=n;j++){
    if(a[i][j]==1&&v[j]==0){
      printf("%d->%d ",i,j);
      count++;
      visit(j);
    }
  }
}

int main(){
  int i,k;

  cin>>n;
  a=new int*[n+1];
  vv=new int*[n+1];
  v = new int[n+1];

  for(i=1;i<=n;i++){  //인접행렬 입력
    a[i]=new int[n+1];
    vv[i]=new int[n+1];
    for(k=1;k<=n;k++){
      cin>>a[i][k];
      vv[i][k]=0;
    }
  }

  for(int m=0;m<=n;m++){  //v행렬 초기화
    v[m]=0;
  }

  for(k=1;k<=n;k++){  //인접행렬 탐색 및 경로 출력
    for(i=1;i<=n;i++) //행번호에 마다 각자 연결된 V를 탐색(자신으로 오는 경로 포함)
      v[i]=0;
    count=0;
    visit(k);
    printf("\n");
  }

  return 0;
}
