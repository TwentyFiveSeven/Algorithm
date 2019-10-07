#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;

int chek[3][10],input,output,karr[10000];
vector<int> prime,prime2;
int flag=0;
queue<pair<int,int>> Q;

void make(){
  int *arr;
  arr = (int *)malloc(sizeof(int)*101);
  int i;
  for(i=2;i<=100;i++){
    arr [i] = i;
  }

  for(i=2;i<=100;i++){
    if(arr[i] == 0)
      continue;
    else
      prime.push_back(i);
    for(int j=i + i;j<=100;j+=i)
      arr[j] = 0;
  }
  free(arr);
  return;
}

int check(int value){
  for(int i=0;i<prime2.size();i++){
    if(!(value%prime2[i])){
      return 0;
    }
  }
  return 1;
}

int bfs(int value,int count){
  int ans,countN;
  karr[value] = 1;
  Q.push(make_pair(value,count));
  while(!Q.empty()){
    ans = Q.front().first;
    countN = Q.front().second;
    Q.pop();
    if(ans == output){
      return countN;
    }
    for(int i=3;i>=0;i--){
      int mul =1;
      for(int j=0; j<i;j++)
        mul *=10;
      for(int j=0;j<=9;j++){
        int temp = (ans/mul)%10;
        if((i==3&&j==0)||temp == j) continue;
        temp = ans - temp*mul + j*mul;
        if(check(temp)&&!karr[temp]){
          karr[temp] = 1;
          Q.push(make_pair(temp,countN+1));
        }
      }
    }
  }
  return -1;
}

int main(){
  int i,j,t,ans;
  scanf("%d",&t);
  make();
  prime2 = prime;
  while(t--){
    scanf("%d %d",&input,&output);
    int answer = bfs(input,0);
    if(answer == -1){
      printf("Impossible\n");
    }else{
      printf("%d\n",answer);
    }
    for(i=1000;i<=10000;i++)
      karr[i] = 0;
    while(!Q.empty())
      Q.pop();
  }
}
