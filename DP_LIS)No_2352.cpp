#include<iostream>
#include<vector>
using namespace std;

int arr[40000],N;
vector<int> V;
int main(){
  int i,j;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&arr[i]);
  }
  for(i=0;i<N;i++){
    int idx = lower_bound(V.begin(),V.end(),arr[i])-V.begin(); //-V.begin() 을 통해서 몇번 째 인자인지 알 수 있다
    printf("idx : %d, size() : %d\n",idx,V.size());
    if(idx == V.size()){  //인자와 V.size()가 같다는 말은 arr[i]가 V안에 없다는 것 = arr[i]가 V안에 수들보다 크다는 것
      V.push_back(arr[i]);  // 이말은 즉 count가 된다 이므로 push한다.
    }else{
      V[idx] = arr[i]; //같지 않다는 것은 V안에 있는 수 중에 arr[i]로 더작은 수를 저장 할 수 있다는 것이다.
    }
  }
  printf("%d",V.size());
  return 0;
}
