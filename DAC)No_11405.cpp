#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<long long> V;
long long result;
long long dac(int left, int right){
  if(left == right)
    return V[left];
  int mid = (left+right)/2;

  long long Lval = dac(left,mid);
  long long Rval = dac(mid+1,right);

//양쪽 끝 뿐만 아니라 가운데도 확인해줘야한다.
  result = max(Lval,Rval);
  int leftindex = mid-1, rightindex = mid+2;
  long long center = min(V[mid],V[mid+1]);
  long long size = 2;
  result = max(result,center*size);

  while(leftindex>=left && rightindex<=right){
    if(V[rightindex]<V[leftindex]){
      center = min(center,V[leftindex]);
      leftindex--;
    }else{
      center = min(center,V[rightindex]);
      rightindex++;
    }
    size++;
    result = max(result,center*size);
  }

  while(leftindex>=left){
    center = min(center,V[leftindex]);
    leftindex--;
    size++;
    result = max(result,center*size);
  }

  while(rightindex<=right){
    center = min(center,V[rightindex]);
    rightindex++;
    size++;
    result = max(result,center*size);
  }

  return result;

}

int main(){
  int n,val;
  while(1){
    scanf("%d",&n);
    if(n == 0) break;
    for(int i=0;i<n;i++){
      scanf("%d",&val);
      V.push_back(val);
    }
    long long result = dac(0,n-1);
    printf("%lld\n",result);
    V.clear();
  }
}
