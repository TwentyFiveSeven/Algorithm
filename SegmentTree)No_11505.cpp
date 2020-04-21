#include<iostream>
using namespace std;
#define G 1000000007
int N,M,K,arr[1000001];
long long segT[1<<21];

long long segtree(int index, int l,int r){
  if(l == r)
    segT[index] = arr[l];
  else{
    segT[index] = (segtree(index*2+1,l,(l+r)/2)%G*segtree(index*2+2,(l+r)/2+1,r)%G)%G;
  }
  return segT[index];
}

long long Mul(int l,int r,int index, int start, int end){
  if(r < start || l > end)
    return 1;
  else if( start >= l && end <=r){
    return segT[index];
  }else{
    return (Mul(l,r,index*2+1,start,(start+end)/2)%G*Mul(l,r,index*2+2,(start+end)/2+1,end)%G)%G;
  }
}

long long Change(int locate,int changeV, int Bef, int index,int start,int end){
  if(locate < start || locate > end)
    return segT[index];
  if(start == end){
    return segT[index] = changeV;
  }
  return segT[index] = (Change(locate,changeV,Bef,index*2+1,start,(start+end)/2)%G*Change(locate,changeV,Bef,index*2+2,(start+end)/2+1,end)%G)%G;
}

int main(){
  int a,b,c;
  cin>>N>>M>>K;
  for(int i=0;i<N;i++)
    cin>>arr[i];
  segtree(0,0,N-1);
  int val = M+K;
  for(int i=0;i<val;i++){
    cin>>a>>b>>c;
    if(a == 1){
      Change(b-1,c,arr[b-1],0,0,N-1);
    }else{
      cout<<Mul(b-1,c-1,0,0,N-1)<<'\n';
    }
  }
}
