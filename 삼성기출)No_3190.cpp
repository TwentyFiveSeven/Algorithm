#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n,k,arr[100][100],Ssize=1;
vector<pair<int,int>> snake;
queue<pair<int,int>> Q;
int xi[4] = {0,1,0,-1};
int yi[4] = {1,0,-1,0};

int play(){
  int count=0,x=0,y=0,num=0,i,j;

  while(1){
    if(!Q.empty()&&Q.front().first == count){
      // reverse(snake.begin(),snake.end());
      if(Q.front().second ==1){
        num +=1;
        if(num>3) num = 0;
      }else{
        num -=1;
        if(num<0) num = 3;
      }
      Q.pop();
    }
    x += xi[num]; y += yi[num];
    // printf("x : %d, y : %d\n",x,y);
    if(x<0||x>=n||y<0||y>=n) return count+1;
    if(arr[x][y] != 0 ) Ssize++;
    reverse(snake.begin(),snake.end());
    snake.push_back(make_pair(x,y));
    reverse(snake.begin(),snake.end());
    // printf("before : %d\n",snake.size());
    for(i=1;i<snake.size();i++){
      // printf("%d %d %d %d\n",x,y,i,snake.size());
      if(x == snake[i].first && y == snake[i].second) return count+1;
    }
    for(i=snake.size();i>Ssize;i--){
      snake.pop_back();
    }
    // printf("after : %d\n",snake.size());
  count++;
  // printf("%d\n",count);
  }
}

int main(){
  int Anum,x,y,i,j,time,turnN;
  char dir;
  scanf("%d",&n);
  scanf("%d",&Anum);
  for(i=0;i<Anum;i++){
    scanf("%d %d",&x,&y);
    arr[x-1][y-1] = 1;
  }
  scanf("%d",&turnN);
  for(i=0;i<turnN;i++){
    scanf("%d %c",&time,&dir);
    if(dir =='D') Q.push(make_pair(time,1));
    else Q.push(make_pair(time,0));
    scanf("%c",&dir);
  }
  printf("%d",play());
  return 0;
}
