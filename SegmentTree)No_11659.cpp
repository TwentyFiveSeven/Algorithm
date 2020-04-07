#include<iostream>
#include<math.h>
using namespace std;
int N,M,arr[100001],*segT;

int segtree(int index, int start, int end){
  if(start == end)
    segT[index] = arr[start];
  else
    segT[index] = segtree(2*index+1,start,(start+end)/2) + segtree(2*index+2,(start+end)/2+1,end);
  return segT[index];
}

int sum(int index, int start, int end, int l, int r){
  if(start > r || end < l)
    return 0;
  else if(start >=l && end<=r)
    return segT[index];
  else{
    int mid = (start+end)/2;
    return sum(2*index+1,start,mid,l,r)+sum(2*index+2,mid+1,end,l,r);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int l,r;
  cin>>N>>M;
  for(int i=0;i<N;i++){
    cin>>arr[i];
  }
  int h = ceil(log2(N));
  int size = 1<<(h+1);
  segT = new int[size];
  segtree(0,0,N-1);
  for(int i=0;i<M;i++){
    cin>>l>>r;
    cout<<sum(0,0,N-1,l-1,r-1)<<'\n';
  }
  return 0;
}
