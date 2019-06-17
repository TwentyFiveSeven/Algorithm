#include<iostream>
#include<algorithm>

using namespace std;

int minvalue=999999;
int arr[1000001];

int findI(int input){
  int count=0;
    if(input%3 ==0){
      input = input/3;
    }else if(input%2 ==0){
      input = input/2;
    }else{
      input = input-1;
    }
  count = arr[input]+1;   // 나누기3, 나누기2, 빼기 1 중에 가능한 연산을 먼저 하고 최적의 값을 더한다.
  return count;
}

int chain(int input){
  int ans = 0,start=2;
  arr[1]=0;
  arr[0]=0;
  input = input-1;
  while(input--){
      minvalue = min(arr[start-2]+2,arr[start-1]+1);      //현재 찾는 값의 최솟값을 찾기위해
      arr[start] = min(minvalue,findI(start));            //2 or 3으로 나눌 수 있는 상황에서 -1,-2 연산을 먼저 했을 때를 체크해준다.
      start = start+1;
  }
}

int main(){
  int input =0,count=0,tmp=0;

  scanf("%d",&input);
  chain(input);
  printf("%d",arr[input]);

  return 0;
}
