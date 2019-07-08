#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

int arr[101][101][101];     //위 아래 박스도 고려하기 위한 3차원 배열
int check[101][101][101];   //위 아래 박스도 고려하기 위한 3차원 배열

int xi[6] = {0,0,1,-1,0,0}; // 위 아래 앞 뒤 오른쪽 왼쪽  이렇게 6개 방향을 확인한다
int yi[6] = {0,0,0,0,1,-1}; // 위 아래 앞 뒤 오른쪽 왼쪽  이렇게 6개 방향을 확인한다
int zi[6] = {1,-1,0,0,0,0}; // 위 아래 앞 뒤 오른쪽 왼쪽  이렇게 6개 방향을 확인한다

queue<tuple<int,int,int>> Q;  // 상자의 순서를 기억하기위한 tuple
int allcount[101];  // 모든 상자의 토마토 개수.
int checkcount[101];  // 모든 상자의 토마토 개수( 익은 날짜로 활용)
int n,m,maxvalue,h;

void bfs(){
  int i,j,x,y,nx,ny,countnum=0,z,nz;

  while(!Q.empty()){
    x = get<1>(Q.front());// tuple 은 get<얻고자하는 값의 순서>(값을 포함한 객체) 이렇게 사용한다.
    y = get<2>(Q.front());  // 박스를 고려하기위한 z를 추가하였다.
    z = get<0>(Q.front());
    Q.pop();
    for(i=0;i<6;i++){
      nx = x + xi[i];
      ny = y + yi[i];
      nz = z + zi[i];
      if(nz>=1&&nz<=h&&nx>=1&& nx<=n&&ny>=1&&ny<=m&&!arr[nz][nx][ny]&&!check[nz][nx][ny]){  //범위안에 있는 z고려.
        Q.push(make_tuple(nz,nx,ny));
        checkcount[nz]++;
        check[nz][nx][ny] = check[z][x][y]+1; //현재 토마토를 익게 한 토마토의 익은 날짜 + 1
        maxvalue = check[nz][nx][ny];
      }
    }
  }
  for(i=1;i<=h;i++){    //모든 상자가 가지고 있는 토마토가 다 익었는지 확인.
    if(allcount[i] == checkcount[i])
        countnum++;
    }
  if(countnum==h)   //h 만큼의 상자의 모든 토마토가 다 익었다면 걸린 날짜를 출력.
    printf("%d",maxvalue);
  else
    printf("-1");
}

int main(){
  int i,j,k;

  scanf("%d %d %d",&m,&n,&h);
  for(i=1;i<=h;i++){
    allcount[i] = n*m;
  }

  for(k=1;k<=h;k++){
    for(i=1;i<=n;i++){
      for(j=1;j<=m;j++){
        scanf("%d",&arr[k][i][j]);
        if(arr[k][i][j] ==1){
          Q.push(make_tuple(k,i,j));
          checkcount[k]++;
        }else if(arr[k][i][j] ==-1){
          allcount[k]--;
        }
      }
    }
  }
  bfs();

  return 0;
}
