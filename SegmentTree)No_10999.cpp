#include<iostream>
#include<math.h>
using namespace std;
int N,M;
long long *segT,arr[1000001],*lazy;

long long segtree(int index, int start, int end){
  if(start == end)
    segT[index] = arr[start];
  else
    segT[index] = segtree(2*index+1,start,(start+end)/2) + segtree(2*index+2,(start+end)/2+1,end);
  return segT[index];
}

long long sum(int index, int start, int end, int l, int r){
  if(lazy[index] != 0){
    segT[index] += (end-start+1)*lazy[index];
    if(start != end){
      lazy[index*2+1] += lazy[index];
      lazy[index*2+2] += lazy[index];
    }
    lazy[index] = 0;
  }
  if(start > r || end < l)
    return 0;
  else if(start >=l && end<=r)
    return segT[index];
  else{
    int mid = (start+end)/2;
    return sum(2*index+1,start,mid,l,r)+sum(2*index+2,mid+1,end,l,r);
  }
}

void update(int changel, int changer, long long changeV,int index, int start, int end){
  printf("index : %d\n",index);
  if(lazy[index] != 0){
    segT[index] += (end-start+1)*lazy[index];
    if(start != end){
      lazy[index*2+1] += lazy[index];
      lazy[index*2+2] += lazy[index];
    }
    lazy[index] = 0;
  }

  if(changel > end || changer < start)
    return;

  if(start>=changel && end <= changer){
    printf("in ,, index : %d\n",index);
    segT[index] +=(end-start+1)*changeV;
    if(start != end){
      lazy[index*2+1] += changeV;
      lazy[index*2+2] += changeV;
    }
    return;
  }
  update(changel,changer,changeV,index*2+1,start,(start+end)/2);
  update(changel,changer,changeV,index*2+2,(start+end)/2+1,end);
  segT[index] = segT[index*2+1]+segT[index*2+2];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int l,r,K,a,b,c;
  cin>>N>>M>>K;
  for(int i=0;i<N;i++){
    cin>>arr[i];
  }
  int h = ceil(log2(N));
  long long size = 1<<(h+1);
  segT = new long long[size];
  lazy = new long long[size];
  for(int i=0;i<size;i++) {
    segT[i] = 0;
    lazy[i] = 0;
  }
  segtree(0,0,N-1);
  for(int i=0;i<size;i++) printf("%lld ",segT[i]);
  printf("\n");
  M = M+K;
  for(int i=0;i<M;i++){
    cin>>a>>b>>c;
    if(a==1){
      long long d;
      cin>>d;
      update(b-1,c-1,d,0,0,N-1);
    }else{
      cout<<sum(0,0,N-1,b-1,c-1)<<'\n';
    }
  }
  return 0;
}
