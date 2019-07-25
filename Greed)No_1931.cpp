#include<iostream>
#include<queue>
#include<vector>
using namespace std;
  //공공소유물에 대한 여러사람의 이용은 가장 먼저 끝나는 작업들을 먼저 하면서 최적을 구할 수 있다.

struct cmp{ // 비교 함수 (1.끝나는 시간 2.끝나는 시간이 같다면 시작하는 시간이 작은게 우선순위.)
  bool operator()(pair<int,int> t,pair<int,int> u){
    if(t.second ==u.second){
      return t.first > u.first;
    }
    return t.second > u.second;
  }
};

priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq; //pq선언하는거 기억하자. <저장할 자료형(ex)int),저장방법,비교함수>

int main(){
  int n=0,a=0,b=0,count=1,save=0,i;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d %d",&a,&b);
    pq.push(make_pair(a,b));
  }
  save = pq.top().second;
  pq.pop();
  for(i=2;i<=n;i++){
    if(pq.top().first >=save){  //현재 회의의 시작시간이 이전 회의의 끝나는 시간과 같거나 늦다면 가능
      save = pq.top().second;
      count++;
    }
    pq.pop();
  }

  printf("%d",count);
  return 0;
}
