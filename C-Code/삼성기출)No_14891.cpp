#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> V;
int connect[4],Direct[4];
// 0 같은 부호, 1 다른 부호
int main(){
  int i,j,input,N,K,D,tmp,mul=1,sum=0;
  for(i=0;i<4;i++){
    vector<int> a;
    for(j=0;j<8;j++){
      scanf("%1d",&input);
      a.push_back(input);
    }
    V.push_back(a);
  }
  scanf("%d",&K);

  for(i=0;i<K;i++){
    scanf("%d %d",&N,&D);
    for(j=0;j<3;j++){ //연결 유무 확인.
      if(V[j][2] != V[j+1][6]) connect[j] =1;
    }
    Direct[N-1] = D;
    for(j=N;j<4;j++){ //N-1을 기준으로 보다 큰번호의 태엽
      if(!connect[j-1]) break;
      Direct[j] = 1;
      if(Direct[j-1]== 1) Direct[j] = -1;
    }
    for(j=N-2;j>=0;j--){  //N-1을 기준으로 보다 작은번호의 태엽 만약 연결이 끊겨있다면 break;
      if(!connect[j]) break;
      Direct[j] = 1;
      if(Direct[j+1]== 1) Direct[j] = -1;
    }

    for(j=0;j<4;j++){ //태엽을 돌리는 작업을 진행한다.
      if(Direct[j] == 1){
        tmp = V[j][7];
        V[j].pop_back();
        V[j].insert(V[j].begin(),tmp);
      }else if(Direct[j] == -1){
        tmp = V[j][0];
        V[j].erase(V[j].begin());
        V[j].push_back(tmp);
      }
    }
    for(j=0;j<4;j++){
      connect[j] = 0;
      Direct[j] = 0;
    }
  }
  for(i=0;i<4;i++){
    sum += V[i][0]*mul;
    mul *=2;
  }
  printf("%d",sum);
  return 0;
}
