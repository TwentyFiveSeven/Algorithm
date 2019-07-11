#include<iostream>
#include<queue>

using namespace std;
int arr[100];
queue<pair<int,int>> Q;
struct val{
  int num;
  int alpha;
  val(int a,int b):alpha(b),num(a){}
};

struct cmp{
  bool operator()(val t,val u){
    return t.num<u.num;
  }
};

int main(){
  int t=0,n=0,m=0,import=0,i,j,count=0;
  priority_queue<val,vector<val>,cmp> pq;
  priority_queue<val,vector<val>,cmp> pq2;
  scanf("%d",&t);

  while(t--){
    count =0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
      scanf("%d",&import);
      if(i!=0&&pq.top().num<import){
        while(!pq.empty()){
          printf("output => alpha : %d, num : %d\n",pq.top().alpha,pq.top().num);
          Q.push(make_pair(pq.top().num,pq.top().alpha));
          // pq2.push(pq.top());
          pq.pop();

        }
      }
      pq.push(val(import,i));
      printf("input => alpha : %d, num : %d\n",i,import);
    }
    while(!Q.empty()){
      printf("reinput => alpha : %d, num : %d\n",Q.front().first,Q.front().second);
      pq.push(val(Q.front().first,Q.front().second));
      Q.pop();
    }
    for(i=0;i<n;i++){
      count++;
      printf("alpha : %d, num : %d\n",pq.top().alpha,pq.top().num);
      if(m == pq.top().alpha){
        printf("%d\n",count);
      }
      pq.pop();
    }
    while(!pq.empty()){
      pq.pop();
    }
  }
}
