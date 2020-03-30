#include<iostream>
#include<string.h>
using namespace std;
int N,arr[10001],depth[10001];

int Find(int a,int b){
  if(a == b) return a;
  if(depth[a] == depth[b]){
    while(a != b){
      a = arr[a];
      b = arr[b];
    }
    return a;
  }else{
    if(depth[a] > depth[b]){
      while(depth[a] != depth[b])
        a = arr[a];
      while(a != b){
        a = arr[a];
        b = arr[b];
      }
      return a;
    }else{
      while(depth[a] != depth[b])
        b = arr[b];
      while(a != b){
        a = arr[a];
        b = arr[b];
      }
      return a;
    }
  }
}

int Makedepth(int now){
  if(arr[now] == 0)
  return 0;
  int next = arr[now];
  if(depth[now] != 0)
    return depth[now];
  depth[now] = Makedepth(next) +1;
  return depth[now];
}

int main(){
  int T,a,b;
  cin>>T;
  while(T--){
    cin>>N;
    for(int i = 0;i<N-1;i++){
      cin>>a>>b;
      arr[b] = a;
    }
    cin>>a>>b;
    for(int i=1;i<=N;i++){
      if(depth[i] == 0 && arr[i] != 0){
        Makedepth(i);
      }
    }
    int ret =  Find(a,b);
    cout<<ret<<'\n';
    memset(arr,0,sizeof(arr));
    memset(depth,0,sizeof(depth));
  }
}
