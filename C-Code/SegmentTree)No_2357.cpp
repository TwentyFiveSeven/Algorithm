#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int N,M,arr[100001],*MinT,*MaxT;

int MinsegmentTree(int index,int start,int end){
  if(start == end)
    MinT[index] = min(MinT[index],arr[start]);
  else{
    int mid = (start+end)/2;
    MinT[index] = min(MinsegmentTree(index*2+1,start,mid),MinsegmentTree(index*2+2,mid+1,end));
  }
  return MinT[index];
}

int MaxsegmentTree(int index,int start,int end){
  if(start == end)
    MaxT[index] = max(MaxT[index],arr[start]);
  else{
    int mid = (start+end)/2;
    MaxT[index] = max(MaxsegmentTree(index*2+1,start,mid),MaxsegmentTree(index*2+2,mid+1,end));
  }
  return MaxT[index];
}

int Minfind(int index, int start, int end, int l,int r){
  if(l > end || r <start)
    return 1000000001;
  else if(start >=l && r >= end){
    return MinT[index];
  }else{
    int mid = (start+end)/2;
    return min(Minfind(index*2+1,start,mid,l,r),Minfind(index*2+2,mid+1,end,l,r));
  }
}

int Maxfind(int index, int start, int end, int l,int r){
  if(l > end || r <start)
    return 0;
  else if(start >=l && r >= end){
    return MaxT[index];
  }else{
    int mid = (start+end)/2;
    return max(Maxfind(index*2+1,start,mid,l,r),Maxfind(index*2+2,mid+1,end,l,r));
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>N>>M;
  int h = ceil(log2(N));
  int size = (1<<(h+1));
  MinT = new int[size];
  MaxT = new int[size];
  for(int i=0;i<size;i++) {
    MinT[i] = 1000000001;
    MaxT[i] = 0;
  }
  for(int i=0;i<N;i++){
    cin>>arr[i];
  }
  MinsegmentTree(0,0,N-1);
  MaxsegmentTree(0,0,N-1);
  int l,r,MaxV,MinV;
  for(int i=0;i<M;i++){
    cin>>l>>r;
    MaxV = Maxfind(0,0,N-1,l-1,r-1);
    MinV = Minfind(0,0,N-1,l-1,r-1);
    cout<<MinV<<' '<<MaxV<<'\n';
  }
  return 0;
}
