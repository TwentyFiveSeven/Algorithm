#include<iostream>
#include<queue>
#include<list>
using namespace std;

struct val{   //pair 가 아닌 구조체를 이용해서 pair를 만들어준다. priority queue를 사용하기위해 compare함수가 필요하기 때문
  int num;
  int alpha;
  val(int a,int b): num(a),alpha(b){} //생성자.
};

struct cmp{       //compare함수를 내림차순으로 정해준다.
  bool operator()(val t,val u){
    return t.num<u.num;
  }
};

int main(){
  int t=0,n=0,m=0,import=0,i,j,count=0;
  priority_queue<val,vector<val>,cmp> pq; //pq로는 입력 값을 크기순으로 받는다.
  list<val> L;  // list로는 입력 값을 순서대로 받는다.
  scanf("%d",&t);

  while(t--){
    count =0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
      scanf("%d",&import);
      pq.push(val(import,i));
      L.push_back(val(import,i));
    }

    while(!pq.empty()){
      if(pq.top().num == L.front().num){  // 만약 pq 와 list 의 각각 처음 값들이 같다면
        count++;
        if(L.front().alpha == m){ // + 첫번째에 있는 값이 찾던 값이라면 count를 출력하고 탐색을 마친다.
          printf("%d\n",count);
          break;
        }
        L.pop_front();pq.pop(); //첫번째 값은 같지만 찾던 값이 아니라면 pq와 list의 front를 pop해주어 다음 수로 넘어간다.
      }else{  //처음 값들이 서로 다르다면 list에 있는 맨앞 값이 가장 큰 수가 나오기 전까지 맨앞 값을 맨 뒤로 이동시킨다.
        L.push_back(L.front());
        L.pop_front();
      }
    }
    while(!pq.empty())  //다음 차례로 넘어가기위해 pq와 list안에 값들을 비워준다.
      pq.pop();
    while(!L.empty())
      L.pop_front();
  }
  return 0;
}
