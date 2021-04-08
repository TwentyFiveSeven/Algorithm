#include<iostream>
#include<cmath>
using namespace std;

int arr[100001],N,M;
long long *segT;
long long makeTree(int index, int start, int end){
  if(start == end)
    return segT[index] = arr[start];
  return segT[index] = makeTree(index*2+1,start,(start+end)/2)+makeTree(index*2+2,(start+end)/2+1,end);
}

long long change(int locate, int val, int index, int start, int end){
  if(locate < start || locate > end)
    return segT[index];
  if(start == end)
    return segT[index] += val;
  return segT[index] = change(locate,val,index*2+1,start,(start+end)/2)+change(locate,val,index*2+2,(start+end)/2+1,end);
}

long long query(int l,int r, int index, int start, int end){
  if(r<start || l>end)
    return 0;
  if(start>=l && end <= r)
    return segT[index];
  return query(l,r,index*2+1,start,(start+end)/2)+query(l,r,index*2+2,(start+end)/2+1,end);
}

int main(){
  cin>>N;
  int h = ceil(log2(N)),a,b,c,Q;
  int size = 1<<(h+1);
  segT = new long long[size];
  for(int i=0;i<size;i++) segT[i] = 0;
  for(int i=0;i<N;i++)
    cin>>arr[i];
  makeTree(0,0,N-1);
  for(int i=0;i<size;i++){
    cout<<segT[i]<<" ";
  }
  cout<<'\n';
  cin>>M;
  for(int i=0;i<M;i++){
    cin>>Q;
    if(Q == 1){
      cin>>a>>b>>c;
      change(a-1,c,0,0,N-1);
      change(b,-c,0,0,N-1);
      for(int i=0;i<size;i++){
        cout<<segT[i]<<" ";
      }
      cout<<'\n';
    }else{
      cin>>a;
      cout<<query(0,a-1,0,0,N-1)<<'\n';
    }
  }
  return 0;
}
