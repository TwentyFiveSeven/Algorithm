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
    if(!Q.empty()&&Q.front().first == count){ //만약 턴하는 시간이 돼었다면.
      // reverse(snake.begin(),snake.end());
      if(Q.front().second ==1){ // 오른쪽일 때
        num +=1;
        if(num>3) num = 0;  //3을 초과하면 다시 0의 방향으로 진행
      }else{
        num -=1;
        if(num<0) num = 3;  //0보다 작아지면 다시 3의 방향으로 진행
      }
      Q.pop();
    }
    x += xi[num]; y += yi[num]; //뱀의 머리 이동
    if(x<0||x>=n||y<0||y>=n) return count+1;  // 머리가 틀 밖으로 나갔으면 게임종료.
    if(arr[x][y] != 0 ){
      Ssize++;  //사과를 먹었다면 size 증가
      arr[x][y] = 0;  //사과 제거
    }
    reverse(snake.begin(),snake.end()); //뱀의 앞뒤를 뒤집어서 머리부분 추가.
    snake.push_back(make_pair(x,y));
    reverse(snake.begin(),snake.end()); // 다시 원상복귀
    for(i=1;i<snake.size();i++){
      if(x == snake[i].first && y == snake[i].second) return count+1; //만약 머리가 뱀의 몸통과 겹친다면 게임 종료
    }
    for(i=snake.size();i>Ssize;i--){  //머리부터 size만큼 남기고 나머지 pop
      snake.pop_back();
    }
  count++; //진행이 끝났다면 1초 ++
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
