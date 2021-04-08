#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,countI[1000],countD[1000],Max,Min;
vector<int> arr;
void LIC(int order){
  int j,i;
  if(order==1) reverse(arr.begin(),arr.end());  //만약 order = 1일 때는 감소하는 수열을 구해야하므로 반대로 뒤집는다.
  for(i=0;i<n;i++){
    Max =0; //Max는 옮겨갈 때 마다 초기화.
    for(j=0;j<=i;j++){
      if(arr[i]>arr[j]&&(order<1 ? countI[j] : countD[j])>Max){ //누적 갯 수가 더 많은 것을 현재 숫자 카운트에 가져와 +1
        (order<1 ? countI[i] : countD[i]) = (order<1 ? countI[j] : countD[j])+1;
        Max = (order<1 ? countI[j] : countD[j]);  //누적 갯수가 가장 많은 것을 사용.
      }
      if(!(order<1 ? countI[i] : countD[i])) (order<1 ? countI[i] : countD[i] )=1;  //만약 앞에 어떠한 것과 비교가 안된다면 1
    }
  }
  if(order==1){
    for(i=0;i<n;i++){ //countD는 reverse를 통해 구했기 때문에 반대부터가 countI의 앞부분이다.
      countI[i] +=countD[n-1-i];  //증가하는 수열과 감소하는 수열의 각각 해당하는 부분들을 더한다.
      if(countI[i]>Max) Max = countI[i];  //가장 큰 수를 구한다.
    }
    printf("%d",Max-1);
  }
}

int main(){
  int i,j,ans=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&j);
    arr.push_back(j);
  }
  for(i=0;i<2;i++){ //하나는 증가하는 수열, 하나는 감소하는 수열을 구한다.
    LIC(i);
  }
  return 0;
}
