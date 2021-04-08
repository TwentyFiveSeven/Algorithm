#include<iostream>
#include<cmath>
using namespace std;

int N,K,*MaxsegT,*MinsegT,*arr;

int MaxmakeTree(int index, int start,int end){
  if(start == end){
    MaxsegT[index] = start;
  }
  else
    MaxsegT[index] = max(MaxmakeTree(index*2+1,start,(start+end)/2),MaxmakeTree(index*2+2,(start+end)/2+1,end));
  return MaxsegT[index];
}

int MinmakeTree(int index, int start,int end){
  if(start == end){
    MinsegT[index] = start;
  }
  else
    MinsegT[index] = min(MinmakeTree(index*2+1,start,(start+end)/2),MinmakeTree(index*2+2,(start+end)/2+1,end));
  return MinsegT[index];
}

int Maxupdate(int now, int change, int index, int start,int end){
  if( now <start || now > end)
    return MaxsegT[index];
  if(start == end)
    return MaxsegT[index] = change;
  return MaxsegT[index] = max(Maxupdate(now,change,index*2+1,start,(start+end)/2),Maxupdate(now,change,index*2+2,(start+end)/2+1,end));
}

int Minupdate(int now, int change, int index, int start,int end){
  if( now <start || now > end)
    return MinsegT[index];
  if(start == end)
    return MinsegT[index] = change;
  return MinsegT[index] = min(Minupdate(now,change,index*2+1,start,(start+end)/2),Minupdate(now,change,index*2+2,(start+end)/2+1,end));
}

int MaxFind(int l,int r,int index,int start,int end){
  if(l > end || r <start)
    return 0;
  if(start >= l && end <=r)
    return MaxsegT[index];
  return max(MaxFind(l,r,index*2+1,start,(start+end)/2),MaxFind(l,r,index*2+2,(start+end)/2+1,end));
}

int MinFind(int l,int r,int index,int start,int end){
  if(l > end || r <start)
    return 200000001;
  if(start >= l && end <=r)
    return MinsegT[index];
  return min(MinFind(l,r,index*2+1,start,(start+end)/2),MinFind(l,r,index*2+2,(start+end)/2+1,end));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T,a,b,c;
  cin>>T;
  while(T--){
    cin>>N>>K;
    int h = ceil(log2(N));
    int size = 1<<(h+1);
    arr = new int[N];
    MaxsegT = new int[size];
    MinsegT = new int[size];
    for(int i=0;i<N;i++)
      arr[i] = i;
    for(int i=0;i<size;i++) {
      MaxsegT[i] = 0;
      MinsegT[i] = 0;
    }
    MaxmakeTree(0,0,N-1);
    MinmakeTree(0,0,N-1);
    for(int i=0;i<K;i++){
      cin>>a>>b>>c;
      if(a){
        int Ma = MaxFind(b,c,0,0,N-1);
        int Mi = MinFind(b,c,0,0,N-1);
        if(Mi == b && Ma == c)
          cout<<"YES"<<'\n';
        else
          cout<<"NO"<<'\n';
      }else{
        swap(arr[b],arr[c]);
        Maxupdate(b,arr[b],0,0,N-1);
        Maxupdate(c,arr[c],0,0,N-1);
        Minupdate(b,arr[b],0,0,N-1);
        Minupdate(c,arr[c],0,0,N-1);
      }
    }
    delete[] MaxsegT;
    delete[] MinsegT;
    delete[] arr;
  }
  return 0;
}
