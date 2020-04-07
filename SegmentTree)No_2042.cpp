#include<iostream>
#include<math.h>
using namespace std;
int N,M;
long long *segT,arr[1000001];

long long segtree(int index, int start, int end){
  if(start == end)
    segT[index] = arr[start];
  else
    segT[index] = segtree(2*index+1,start,(start+end)/2) + segtree(2*index+2,(start+end)/2+1,end);
  return segT[index];
}

long long sum(int index, int start, int end, int l, int r){
  if(start > r || end < l)
    return 0;
  else if(start >=l && end<=r)
    return segT[index];
  else{
    int mid = (start+end)/2;
    return sum(2*index+1,start,mid,l,r)+sum(2*index+2,mid+1,end,l,r);
  }
}

void update(int changeN, long long changeV,int index, int start, int end){
  if(changeN < start || changeN > end)
    return;

  segT[index] += changeV;

  if(start != end){
    int mid = (start+end)/2;
    update(changeN, changeV, 2*index+1, start, mid);
    update(changeN, changeV, 2*index+2, mid+1, end);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int l,r,K,a,b;
  cin>>N>>M>>K;
  for(int i=0;i<N;i++){
    cin>>arr[i];
  }
  int h = ceil(log2(N));
  long long size = 1<<(h+1);
  segT = new long long[size];
  segtree(0,0,N-1);
  M = M+K;
  for(int i=0;i<M;i++){
    cin>>a>>b;
    if(a==1){
      long long c;
      cin>>c;
      long long diff = c-arr[b-1];
      arr[b-1] = c;
      update(b-1,diff,0,0,N-1);
    }else{
      int c;
      cin>>c;
      cout<<sum(0,0,N-1,b-1,c-1)<<'\n';
    }
  }
  return 0;
}
