#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m,n,k,num;
int vx[4]={1,-1,0,0};
int vy[4]={0,0,-1,1};
vector<int> ans;
int **arr;
int **visit;

void dfs(int x,int y){
  int i,j,px,py;
  for(i=0;i<4;i++){
    px=x+vx[i];py=x+vy[i];//&& !visit[i][j]
    if(px>=0 && px<m && py<n && py>=0 && !arr[px][py]){
      printf("px, py : %d, %d\n",px,py);
      num++;
      printf("num : %d\n",num);
      //visit[i][j]=1;
      dfs(px,py);
    }
  }
}


int main(){
  int x1,y1,x2,y2,i,j,l;

  cin>>m>>n>>k;
  arr = new int*[m];
  visit = new int*[m];
  for(i=0;i<m;i++){
    arr[i]=new int[n];
    visit[i] = new int[n];
    for(j=0;j<n;j++){
      arr[i][j]=0;
      visit[i][j]=0;
    }
  }
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      printf("%d ",visit[i][j]);
    }
    printf("\n");
  }
  for(l=0;l<k;l++){
    cin>>y1>>x1>>y2>>x2;
    for(i=x1;i<x2;i++){
      for(j=y1;j<y2;j++){
        arr[i][j]=1;
      }
    }
  }
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      if(!arr[i][j] && !visit[i][j]){
        visit[i][j]=1;
        num=1;
        printf("1");
        dfs(i,j);
        ans.push_back(num);
      }
    }
  }
  cout<<ans.size()<<endl;
  sort(ans.begin(),ans.end());
  for(i=0;i<k;i++){
    cout<<ans[i]<<" ";
  }
}
