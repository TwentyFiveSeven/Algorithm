#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,arr[20][20],dice[3][3],floor,x,y;
int xi[4] ={0,0,-1,1};
int yi[4] ={1,-1,0,0};

int find(int num){
  int i,j,tmp;
  if(x+xi[num] <0 || x+xi[num]>=n || y+yi[num]<0 || y+yi[num]>=m) return 0;

  vector<int> temp;
  x += xi[num];
  y += yi[num];
  for(i=0;i<3;i++){
    temp.push_back((num<2 ? dice[1][i] : dice[i][1]));
  }
  if(num ==1 || num ==2) reverse(temp.begin(),temp.end());
  tmp = floor;
  floor = temp[2];
  for(i=1;i>=0;i--){
    temp[i+1] = temp[i];
  }
  temp[0] = tmp;

  if(num ==1 || num ==2) reverse(temp.begin(),temp.end());
  for(i=0;i<3;i++){
    (num<2 ? dice[1][i] : dice[i][1]) = temp[i];
  }
  if(arr[x][y] == 0 ){
    arr[x][y] = floor;
  }else{
    floor = arr[x][y];
    arr[x][y] =0;
  }
  // for(i=0;i<3;i++){
  //   for(j=0;j<3;j++){
  //     printf("%d ",dice[i][j]);
  //   }
  //   printf("\n");
  // }
  // printf("0 %d 0 \n",floor);
  // printf("\n");
  printf("%d\n",dice[1][1]);
  return 0;
}

int main(){
  int i,j,k,num,ans;
  scanf("%d %d %d %d %d",&n,&m,&x,&y,&k);

  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      scanf("%d",&arr[i][j]);

  for(i=0;i<k;i++){
    scanf("%d",&num);
    find(num-1);
  }
  return 0;
}
