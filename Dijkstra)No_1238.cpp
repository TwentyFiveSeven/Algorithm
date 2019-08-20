#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct cmp{ //priority queue에 비교를 위한 cmp struct를 선언.
  bool operator()(pair<int,int> a,pair<int,int> b){
    if(a.second != b.second){
      return a.second > b.second;
    }else
      return a.first > b.first;
  }
};
priority_queue<pair<int,int>, vector<pair<int,int>>,cmp> Q; //사용할 자료 , container , 비교구조체
int arr[1000][1000],start[1000],ans[1000],N,M,dest,check[1000];

int dij(int st){  //다익스트라. 배열을 통해 시작점 부터 현재 점에서의 최단거리를 계산 , 다음 차례는 주변 점들 중 가장 길이가 짧은 것 부터 진행
  int i,j,k;
  start[st] = 0;
  Q.push(make_pair(st,0));
  while(!Q.empty()){
    k = Q.top().first;
    Q.pop();
    if(check[k]==1) continue;
    check[k] = 1;
    for(i=0;i<N;i++){
      if(i == k) continue;
      if(arr[k][i]!=0){
        if(start[k]+arr[k][i]<start[i]){  //무한대로 놓는 이유 start[k]는 현재 점부터 시작점까지의 거리,
          start[i] = start[k]+arr[k][i];  //arr[k][i]는 현재 점부터 연결된 점까지의 거리이다. 이중 작은 값으로 start[i] 업데이트
        }
        Q.push(make_pair(i,start[i]));  //start[i](출발점으로부터의 길이)가 가장 짧은게 먼저 진행 된다.
      }
    }
  }
  return start[dest];
}

int main(){
  int i,j,x,y,value,maxN=0;
  scanf("%d %d %d",&N,&M,&dest);
  fill_n(start,N,99999999);
  for(i=0;i<M;i++){
    scanf("%d %d %d",&x,&y,&value);
    arr[x-1][y-1] = value;
  }
  dest -=1;
  for(i=0;i<N;i++){ //각 시작점부터 도착점까지의 거리를 구한다.
    if(i == dest) continue;
    ans[i] = dij(i);
    fill_n(start,N,99999999);
    fill_n(check,N,0);
  }
  dij(dest);  //dest에서 각 점으로 가는 최단 거리 구한다.
  for(i=0;i<N;i++){
    ans[i] += start[i]; //dest까지 가는 거리와 dest에서 각점으로 가는 거리를 더한다.
    if(ans[i]>maxN) maxN = ans[i];
  }
  printf("%d",maxN);
  return 0;
}
