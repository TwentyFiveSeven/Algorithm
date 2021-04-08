#include<iostream>
using namespace std;

int main(){
  int t;
  long long x,y;
  scanf("%d",&t);
  while(t--){
    scanf("%lld %lld",&x,&y);
    long long sum =x,ret=0;
    long long value = 1;
    while(y > sum){
      if(sum + value + value*(value-1)/2 > y){
        value--;
        continue;
      }else if(sum + value + value*(value-1)/2 == y){
        ret += value;
        break;
      }
      sum += value;
      ret++;
      value++;
    }
    printf("%lld\n",ret);
  }
  return 0;
}
