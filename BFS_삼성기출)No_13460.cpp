#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
                    //문제에 제한사항이 많기 때문에 가짓수를 줄이기 위해 특정 경우수를 막게되면 꼭 걸리는 부분이 발생.(가짓수 줄이기 X)
char arr[11][11];
bool check[11][11][11][11]; //이미 지나온 점으로 지나가지않기 위함.
int n,m,minu=0;
int xi[4] = {1,-1,0,0}; //기울이는 방향을 설정. 좌 우 위 아래
int yi[4] = {0,0,1,-1};
queue<tuple<int,int,int>> Q;  //tuple을 위해 count까지 함께 사용.

int bfs(){
  int x1,y1,x2,y2,tmpx,tmpy,nx1,ny1,nx2,ny2,i,j,count=0;
  int z1,z2;
  while(!Q.empty()){
    x1 = get<0>(Q.front());
    y1 = get<1>(Q.front());
    z1 = get<2>(Q.front());
    Q.pop();
    x2 = get<0>(Q.front());
    y2 = get<1>(Q.front());
    z2 = get<2>(Q.front());;
    Q.pop();
    check[x1][y1][x2][y2] = true;
    if(arr[x1][y1] == 'O'&&arr[x2][y2]!=arr[x1][y1])
      {
        return z1;}
    for(i=0;i<4;i++){
      nx1 = x1+xi[i];
      ny1 = y1+yi[i];
      nx2 = x2+xi[i];
      ny2 = y2+yi[i];
      while(arr[nx1][ny1]!='#'&&arr[nx1][ny1] != 'O'){
        nx1 += xi[i];
        ny1 += yi[i];
      }
      while(arr[nx2][ny2]!='#'&&arr[nx2][ny2] != 'O'){
        nx2 += xi[i];
        ny2 += yi[i];
      }
      if(nx1 == nx2 && ny1 == ny2){
        if(arr[nx1][ny1] == 'O') continue;
        if(abs(nx1-x1)+abs(ny1-y1) < abs(nx2-x2)+abs(ny2-y2)){  //겹쳤을 때 이렇게 대비를 해준다. 멀리 있는 것에 -xi[i]*2;
          nx2 -= xi[i]*2;
          ny2 -= yi[i]*2;
          nx1 -= xi[i];
          ny1 -= yi[i];
        }else{
          nx1 -= xi[i]*2;
          ny1 -= yi[i]*2;
          nx2 -=xi[i];
          ny2 -=yi[i];
        }
      }else{
        if(arr[nx2][ny2] =='O'){   //겹치지않았을 때 B가 먼저 O에 도착했다면 continue;
          continue;
        }else if(arr[nx1][ny1]!='O'){
          nx1 -= xi[i];
          ny1 -= yi[i];
          nx2 -= xi[i];
          ny2 -= yi[i];
        }else{  //겹치지않았을 때 R이 먼저 R에 도착하면 return z1+1;
          return z1+1;
        }
      }
      if(check[nx1][ny1][nx2][ny2]) continue; //이미 지나온 점은 다시 돌아가지않는다 .
      Q.push(make_tuple(nx1,ny1,z1+1)); //두 점을 push
      Q.push(make_tuple(nx2,ny2,z2+1));
      check[nx1][ny1][nx2][ny2] = true;
    }
    if(z1 ==10) return -1;
  }
  return -1;
}

int main(){
  int i,j,savex,savey,saveinput;
  char input;
  scanf("%d %d",&n,&m);
  scanf("%c",&input);
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      scanf("%c",&input);
      arr[i][j] = input;
      if(input == 'R') Q.push(make_tuple(i,j,0));
      if(input == 'B') {
        savex = i; savey = j; saveinput = 0;
      }
    }
    scanf("%c",&input);
  }
  Q.push(make_tuple(savex,savey,saveinput));
  printf("%d",bfs());
  return 0;
}
