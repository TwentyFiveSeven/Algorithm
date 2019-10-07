#include<iostream>
#include<vector>
using namespace std;

vector<int> V,A,ANS;
int N,M,Max;

int check(int value){
  int num = 0,i=0;
  int count = 1;
  int save = A[value];
  int money = save;
  while(i<N){
    while(i<N){
      if(money - A[i]<0)
        break;
      money -= A[i];
      i++;
    }
    if(i>=N)
      break;
    count++;
    money = save;
  }
    if(count<=M){
      ANS.push_back(A[value]);
      return 0;
    }
    else
      return 1;
}

void binary(int start, int end){
  int mid = (start+end)/2;
  if(check){
    if(end > mid&&start < mid)
      binary(start, mid);
      binary(mid+1,end);
  }
}

int main(){
  int input;
  scanf("%d %d",&N,&M);
  for(i=0;i<N;i++){
    scanf("%d",&input);
    V.push_back(input);
  }
  A = V;
  sort(V.begin(),V.end());

  binary(0,0,Max);
}
