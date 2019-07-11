#include<iostream>
#include<queue>

using namespace std;
int arr[100];

struct val{
  int num;
  int alpha;
  int input;
  val(int a,int b,int c): num(a),alpha(b),input(c){}
  void change(int i){
    input = i;
  }
};

struct cmp{
  bool operator()(val t,val u){
    if(t.num<u.num)
      return true;
    else if(t.num == u.num){
      return t.input>u.input;
    }else{
      return false;
    }
  }
};

int main(){
  int t=0,n=0,m=0,import=0,i,j,count=0,inputcount=0,outputcount=0;
  priority_queue<val,vector<val>,cmp> pq;
  priority_queue<val,vector<val>,cmp> pq2;
  scanf("%d",&t);

  while(t--){
    count =0;
    outputcount = 0;
    inputcount =0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
      scanf("%d",&import);
      if(i!=0&&pq.top().num<import){
        while(!pq.empty()){
          // printf("output => alpha : %d, num : %d\n",pq.top().alpha,pq.top().num);
          pq2.push(val(pq.top().num,pq.top().alpha,outputcount++));
          pq.pop();

        }
        inputcount =0;
      }
      pq.push(val(import,i,inputcount++));
      // printf("input => alpha : %d, num : %d\n",i,import);
    }
    while(!pq2.empty()){
      // printf("reinput => alpha : %d, num : %d\n",pq2.top().alpha,pq2.top().num);
      pq.push(val(pq2.top().num,pq2.top().alpha,inputcount++));
      pq2.pop();
    }
    for(i=0;i<n;i++){
      count++;
      // printf("alpha : %d, num : %d\n",pq.top().alpha,pq.top().num);
      if(m == pq.top().alpha){
        printf("%d\n",count);
        break;
      }
      pq.pop();
    }
    while(!pq.empty()){
      pq.pop();
    }
  }
  return 0;
}
