#include<iostream>
#include<vector>
using namespace std;
int N,arr[101][101];
vector<int> Move;
int xi[4] = {0,-1,0,1}, yi[4] = {1,0,-1,0},nx=0,ny=0;

void Draw(int x, int y, int depth, int limit){
  if(depth == limit){
    return;
  }
  int size = Move.size();
  for(int i = size-1; i>=0;i--){
    int dir = (Move[i]+1)%4;
    x = x + xi[dir];
    y = y + yi[dir];
    if(x>=0&&x<101&&y>=0&&y<101)
      arr[x][y] = 1;
    Move.push_back(dir);
  }
  Draw(x,y,depth+1,limit);
}

int main(){
  int x,y,d,g,ans =0;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>y>>x>>d>>g;
    arr[x][y] = 1;
    x = x + xi[d];
    y = y + yi[d];
    arr[x][y] = 1;
    Move.push_back(d);
    Draw(x,y,0,g);
    Move.clear();
  }
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      int flag = 0;
      for(int k=i;k<i+2;k++){
        for(int m=j;m<j+2;m++){
          if(arr[k][m] ==0){
            flag = 1;
            break;
          }
        }
        if(flag==1) break;
      }
      if(flag == 0) ans++;
    }
  }
  cout<<ans;
  return 0;
}
