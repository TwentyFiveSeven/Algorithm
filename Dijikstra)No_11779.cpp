#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
const int INF = 1e9;
priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
vector<pair<int,int>> arr[1001];
int V[1001],rem[1001],N,M,End;
vector<int> ans;
int PQ(int start){
  pq.push(make_pair(V[start],start));
  while(!pq.empty()){
    start = pq.top().second;
    int Time = pq.top().first;
    pq.pop();
    for(int i=0;i<arr[start].size();i++){
      int next = arr[start][i].first;
      int nextTime = arr[start][i].second + Time;
      if(V[next] > nextTime){
        V[next] = nextTime;
        pq.push(make_pair(V[next],next));
        rem[next] = start;
      }
    }
  }
  return V[End];
}

int main(){
  int x,y,v,start;
  scanf("%d %d",&N,&M);
  for(int i=1;i<=N;i++)
    V[i] = INF;
  for(int i=0;i<M;i++){
    scanf("%d %d %d",&x,&y,&v);
    arr[x].push_back(make_pair(y,v));
  }
  scanf("%d %d",&start,&End);
  V[start] = 0;
  int ret = PQ(start);
  printf("%d\n",ret);
  int count = 1;
  ans.push_back(End);
  while(End != start){
    End = rem[End];
    ans.push_back(End);
    count++;
  }
  printf("%d\n",count);
  int size = ans.size();
  for(int i=size-1;i>=0;i--){
    printf("%d ",ans[i]);
  }
  return 0;
}
