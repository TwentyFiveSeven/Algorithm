#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;
int count[501],N,V[501],cycle1 = 0,flag2 = 0;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
vector<int> arr[501],ans;

void Sort(){
  cycle1 = 0,flag2 = 0;
  int Co=0;
  while(!Q.empty()){
    Co++;
    int val = Q.top().second;
    Q.pop();
    ans.push_back(val);
    int size = arr[val].size();
    if(size >1){
      flag2 =1;
      break;
    }
    for(int i=0;i<size;i++){
      int next = arr[val][i];
      int temp = V[val];
      V[val] = V[next];
      V[next] = temp;
      if(V[val] !=ans.size()){
        cycle1 = 1;
        break;
      }
      count[next] -=1;
      if(count[next] == 0){
        Q.push(make_pair(V[next],next));
      }
    }
  }
  // if(flag2) return;
  // cout<<"Co : "<<Co<<'\n';
  // if(Co != N) cycle1 = 1;
}

int main(){
  int T,a,b,M;
  cin>>T;
  while(T--){
    cin>>N;
    for(int i=1;i<=N;i++){
      cin>>a;
      V[a] = i;
    }
    cin>>M;
    for(int i=0;i<M;i++){
      cin>>a>>b;
      if(V[a]>V[b]){
        arr[a].push_back(b);
        count[b]++;
      }else{
        arr[b].push_back(a);
        count[a]++;
      }
    }
    for(int i=1;i<=N;i++){
      if(count[i] == 0){
        Q.push(make_pair(V[i],i));
      }
    }
    Sort();
    if(flag2 == 1)
      cout<<"?"<<'\n';
    else if(cycle1 == 1)
      cout<<"IMPOSSIBLE"<<'\n';
    else{
      int Size = ans.size();
      for(int i=0;i<Size;i++){
        cout<<ans[i]<<' ';
      }
      cout<<'\n';
    }
    memset(count,0,sizeof(count));
    memset(V,0,sizeof(V));
    for(int i=0;i<=N;i++)
      arr[i].clear();
    ans.clear();
  }
}
