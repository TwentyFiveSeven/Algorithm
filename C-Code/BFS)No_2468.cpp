#include<iostream>
#include<queue>

using namespace std;

queue<pair<int,int>> Q;

int arr[101][101];
int check[101][101];
int xi[4] = {1,-1,0,0};
int yi[4] = {0,0,1,-1};
int n;

void bfs(int num){
  int i,j,x,y,nx,ny;

  while(!Q.empty()){
    x = Q.front().first;
    y = Q.front().second;
    Q.pop();
    for(i=0;i<4;i++){
      nx = x + xi[i];
      ny = y + yi[i];
      if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&arr[nx][ny]>num&&!check[nx][ny]){
        Q.push(make_pair(nx,ny));
        check[nx][ny] = 1;
      }
    }
  }
}

int main(){
  int i,j,num=0,count=0,max = 0,maxvalue=0;
  scanf("%d", &n);

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      scanf("%d",&arr[i][j]);
      if(arr[i][j]>maxvalue){
        maxvalue = arr[i][j];
      }
    }
  }

  while(num!=maxvalue){     //0 ~ maxvalue의 값까지 비가 내렸을 때 안전 지역의 최대 개수를 구한다.
    count =0;               // num의 값이 바뀔 때 마다 count를 초기화.
    for(i=1;i<=n;i++){      //main에 있는 for문을 통해 bfs에서 나올 때마다 count하면서 따로 떨어진 안전 지역의 수를 구한다.
      for(j=1;j<=n;j++){
        if(arr[i][j]>num&&!check[i][j]){
          Q.push(make_pair(i,j));
          bfs(num);
          count++;
        }
      }
    }
    for(i=1;i<=n;i++){     //num의 값이 바뀔 때 마다 check를 초기화 해준다.
      for(j=1;j<=n;j++){
        check[i][j] =0;
      }
    }
    if(count>max){    //가장많은 안전 지역의 수를 구한다.
      max = count;
    }
    num++;
  }
  printf("%d",max);
  return 0;
}
