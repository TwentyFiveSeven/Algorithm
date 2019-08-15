#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

char arr[11][11];
bool check[11][11][11][11];
int n,m;
int xi[4] = {1,-1,0,0};
int yi[4] = {0,0,1,-1};
queue<tuple<int,int,char>> Q;

int bfs(){
  int x1,y1,x2,y2,tmpx,tmpy,nx1,ny1,nx2,ny2,i,j,count=0;
  char z1,z2;
  while(1){
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
      return count;
    for(i=0;i<4;i++){
      nx1 = x1+xi[i];
      ny1 = y1+yi[i];
      nx2 = x2+xi[i];
      ny2 = y2+yi[i];
      while(arr[nx1][ny1]!='#'&&arr[nx1][ny1] != 'O'){
        printf("%d %d %c\n",x1,y1,z1);
        nx1 += xi[i];
        ny1 += yi[i];
      }
      while(arr[nx2][ny2]!='#'&&arr[nx2][ny2] != 'O'){
        printf("2 : %d %d %c\n",x2,y2,z2);
        nx2 += xi[i];
        ny2 += yi[i];
      }
      if(nx1 == nx2 && ny1 == ny2){
        if(arr[nx1][ny1] == 'O') continue;
        if(abs(nx1-x1)+abs(ny1-y1) < abs(nx1-x2)+abs(nx1-y2)){
          nx2 -=xi[i];
          ny2 -=yi[i];
        }else{
          nx1 -= xi[i];
          ny1 -= yi[i];
        }
      }else{
        nx1 -= xi[i];
        ny1 -= yi[i];
        nx2 -= xi[i];
        ny2 -= yi[i];
      }
      if(check[nx1][ny1][nx2][ny2]) continue;
      printf("input1 : %d %d %c\n",nx1,ny1,z1);
      printf("input2 : %d %d %c\n",nx2,ny2,z2);
      Q.push(make_tuple(nx1,ny1,z1));
      Q.push(make_tuple(nx2,ny2,z2));
      check[nx1][ny1][nx2][ny2] = true;
    }
    if(count ==10) return -1;
    count++;
  }
}

int main(){
  int i,j,savex,savey;
  char input,saveinput;
  scanf("%d %d",&n,&m);
  scanf("%c",&input);
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      scanf("%c",&input);
      arr[i][j] = input;
      if(input == 'R') Q.push(make_tuple(i,j,input));
      if(input == 'B') {
        savex = i; savey = j; saveinput = input;
      }
    }
    scanf("%c",&input);
  }
  Q.push(make_tuple(savex,savey,saveinput));
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  printf("%d",bfs());
  return 0;
}
