#include<iostream>
#include<set>
#include<queue>
using namespace std;
set<pair<int,int>> V;
queue<pair<int,int>> Q;
int arr[51][51],L,R,N,check[51][51],xi[4] ={0,0,1,-1},yi[4]={1,-1,0,0};

int bfs(int a, int b){
  V.clear();
  int count = 0;
  Q.push(make_pair(a,b));
  while(!Q.empty()){
    int x = Q.front().first;
    int y = Q.front().second;
    Q.pop();
    int val = arr[x][y];
    for(int i=0;i<4;i++){
      int nx = x +xi[i];
      int ny = y +yi[i];
      if(nx>=0 && nx <N && ny >=0 &&ny <N&&check[nx][ny] == 0){
        if(abs(val - arr[nx][ny])>=L && abs(val - arr[nx][ny])<=R){
          Q.push(make_pair(nx,ny));
          V.insert(make_pair(nx,ny));
          V.insert(make_pair(x,y));
          check[nx][ny]=1;
        }
      }
    }
  }
  if(!V.size()){
    return 0;
  }
  return 1;
}

int main(){
  cin>>N>>L>>R;
  int count = 0,ans=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>arr[i][j];
    }
  }
  while(1){
    count = 0;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(check[i][j] == 0){
          check[i][j] = 1;
          if(bfs(i,j)){
            count++;
            int sum = 0;
            for(auto iter = V.begin();iter != V.end();iter++)
              sum += arr[(*iter).first][(*iter).second];
            sum = sum/V.size();
            for(auto iter = V.begin();iter != V.end();iter++)
              arr[(*iter).first][(*iter).second] = sum;
          }
        }
      }
    }
    if(count == 0) break;
    ans++;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        check[i][j] = 0;
      }
    }
  }
  cout<<ans;
  return 0;
}
