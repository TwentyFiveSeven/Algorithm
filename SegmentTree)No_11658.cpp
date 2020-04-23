#include<iostream>
using namespace std;
int arr[1048576],segT[2097152];

int makeTree(int index, int start, int end){
  if(start == end)
    return segT[index] = arr[start];
  return segT[index] = makeTree(index*2+1,start,(start+end)/2)+makeTree(index*2+2,(start+end)/2+1,end);
}

int query(int l,int r,int index,int start,int end){
  if(l > end || r <start)
    return 0;
  if(start >=l && end <=r)
    return segT[index];
  return query(l,r,index*2+1,start,(start+end)/2)+query(l,r,index*2+2,(start+end)/2+1,end);
}

int change(int locate, int val, int index,int start,int end){
  if( locate < start || locate > end)
    return segT[index];
  if(start == end)
    return segT[index] = val;
  return segT[index] = change(locate,val,index*2+1,start,(start+end)/2)+change(locate,val,index*2+2,(start+end)/2+1,end);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N,M,x1,x2,y1,y2,sum,a,b,c,W;
  cin>>N>>M;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>arr[i*N+j];
    }
  }
  makeTree(0,0,N*N-1);
  for(int i=0;i<M;i++){
    sum=0;
    cin>>W;
    if(W == 1){
      cin>>x1>>y1>>x2>>y2;
      for(int j=x1-1;j<=x2-1;j++){
        int nx = (j)*N+y1-1;
        int ny = (j)*N+y2-1;
        sum += query(nx,ny,0,0,N*N-1);
      }
      cout<<sum<<'\n';
    }else{
      cin>>a>>b>>c;
      int locate = (a-1)*N+b-1;
      change(locate,c,0,0,N*N-1);
    }
  }
  return 0;
}
