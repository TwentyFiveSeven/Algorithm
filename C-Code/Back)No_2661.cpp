#include<iostream>

using namespace std;

int n,arr[81];

int promising(int depth,int value){
  int flag =0,i,j;
  if(arr[depth-1]==value) return 0; //만일 이전 숫자와 같다면 유망X => 0을 return

  arr[depth] = value; //현재 depth에 value 값을 넣는다.
  for(i=1;i<=depth/2-1;i++){  // 몇번 확인할건지 정한다. (1 ~ depth/2-1 만큼을 확인해야한다 8 => 2,3,4개 짜리를 확인.)
    flag =0;  //계속해서 같은지를 확인 => 계속해서 같다면 유망하지않다 => 0을 return
    for(j=depth;j>=depth-i;j--){  //확인 위치를 depth에서 점점 낮아지면서 현재 추가된 depth 즉 뒤에서 부터 짝지어서 확인
      if(arr[j]!=arr[j-i-1]){ // 8 => 2,3,4개 짜리를 확인해야하고 2개짜리일 때 비교는 8 == 6, 7 == 5 ,3개짜리일 때 비교는 8 == 5, 7 == 4, 6 == 3
        flag = 1;     //만일 비교하는 두개의 숫자가 다르다 =>유망하다 !
      }
    }
    if(flag==0){  // 만일 탐색하고 온 i+1개 짜리 두 배열이(붙어있는 두 배열) 모두 같았다 => 유망하지않다
      arr[depth] = 0; //다시 arr[depth]를 0 으로 돌린다.
      return 0; //유망하지 않다 => 0 을 reutrn
    }
  }
  return 1; //유망하면 1을 return
}

void printSequence(){
  int i;
  for(i=1;i<=n;i++){
    printf("%d",arr[i]);
  }
}

void sequence(int depth){ // sequence 를 통해서 depth가 1 ~n될 때 까지 배열을 채워나간다.
  int i,j;
  if(depth==n+1){ // 만일 depth가 n+1이 된다면 출력 후에 종료(가장 앞에 숫자부터 탐색하기 때문에 처음 찾는 수가 가장 작은 수 이다.)
    printSequence();
    exit(0);
  }

  for(i=1;i<=3;i++){
    if(promising(depth,i)){ // promising을 통해서 유망함을 확인한다.
      sequence(depth+1);  //유망하다면 depth+1의 자리를 구한다.
      arr[depth] = 0; //다시 0으로 값을 넣어서 i++값을 확인한다.
    }
  }
}

int main(){
  scanf("%d",&n);

  sequence(1);
  return 0;
}
