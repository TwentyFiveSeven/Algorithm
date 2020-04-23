#include<iostream>
#include<queue>
using namespace std;
int arr[20][20],size=2,N,count=0,up=0,x,y;
int xi[4] = {-1,0,0,1}, yi[4] = {0,-1,1,0};

struct compare{
  bool operator()(pair<int,int> a,pair<int,int> b){
    if(a.first == b.first)
      return a.second > b.second;
    return a.first >b.first;
  }
};
int bfs(){
  priority_queue<pair<int,int>,vector<pair<int,int>>,compare> K;
  queue<pair<int,int>> Q;
  int save = 1000000001;
  int check[20][20] = {0};
  check[x][y] = 1;
  arr[x][y] = 0;
  Q.push(make_pair(x,y));
  while(!Q.empty()){
    int a = Q.front().first;
    int b = Q.front().second;
    Q.pop();
    int val = check[a][b];
    if(val > save){
      count += save;
      up++;
      x = K.top().first;
      y = K.top().second;
      arr[x][y] = 0;
      return 1;
    }
    for(int i=0;i<4;i++){
      int nx = a + xi[i];
      int ny = b + yi[i];
      if(nx>=0 && nx <N && ny >=0 && ny <N && !check[nx][ny]){
        if(arr[nx][ny] == 0 || arr[nx][ny] == size){
          Q.push(make_pair(nx,ny));
          check[nx][ny] = val+1;
        }else if(arr[nx][ny] >0 && arr[nx][ny] < size){
          Q.push(make_pair(nx,ny));
          K.push(make_pair(nx,ny));
          save = val;
          check[nx][ny] = val+1;
        }
      }
    }
  }
  return 0;
}

int main(){
  cin>>N;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
      cin>>arr[i][j];
      if(arr[i][j] == 9){
        x = i,y = j;
      }
    }
  int flag = 1;
  while(flag){
    flag = bfs();
    if(up == size){
      size++;
      up = 0;
    }
  }
  cout<<count;
  return 0;
}
