#include<iostream>
using namespace std;

int n,m,arr[500][500],maxN;
int triplex[6] = {-1,-1,-1,1,1,1}; //x,y 대칭, 3개의 막대에서 시작, 긴 ㄱ, ㄴ, 돌리고 대칭한 모양
int tripley[6] = {0,1,2,0,1,2};
int doublex[8] = {-1,1,1,-1,-1,-1,1,1}; //2개의 가로 막대에서 시작.ㄱㄴ모양과 ㅁ모양
int doubley[8] = {0,1,0,1,0,1,0,1};
int doublex1[4] = {0,1,0,1};  //2개의 세로 막대에서 시작 ,z모양
int doubley1[4] = {1,-1,-1,1};
int find(){
  int i,j,k,sum=0;
  // 4 가로
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(j+3>=m) break; //막대의 범위 (확실히 잡아줘야함)
      sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i][j+3]; // 더한 값
      if(sum>maxN) maxN = sum;
    }
  }
  // printf("1 : maxN : %d\n",maxN);
  // 4 세로
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(i+3>=n) break;
      sum = arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+3][j];
      if(sum>maxN) maxN = sum;
    }
  }
  // printf("2 : maxN : %d\n",maxN);
  // 3 가로
  for(i =0;i<n;i++){
    for(j=0;j<m;j++){
      if(j+2>=m) break;
      sum = arr[i][j]+arr[i][j+1]+arr[i][j+2];
      for(k=0;k<6;k++){
        if(i+triplex[k]<0||i+triplex[k]>=n ||j+tripley[k]<0||j+tripley[k]>=m) continue; // 추가적인 점의 범위값을 확실히 잡아줘야한다 !!!!!!!!!(이게 포인트)
        // sum+=arr[i+triple[k]][j+triple[k]];
        if(sum+arr[i+triplex[k]][j+tripley[k]]>maxN) maxN = sum+arr[i+triplex[k]][j+tripley[k]];
      }
    }
  }
  // printf("3 : maxN : %d\n",maxN);
  //3 세로
  for(i =0;i<n;i++){
    for(j=0;j<m;j++){
      if(i+2>=n) break;
      sum = arr[i][j]+arr[i+1][j]+arr[i+2][j];
      for(k=0;k<6;k++){
        if(i+tripley[k]<0||i+tripley[k]>=n ||j+triplex[k]<0||j+triplex[k]>=m) continue;
        // sum+=arr[i+triple[k]][j+triple[k]];
        if(sum+arr[i+tripley[k]][j+triplex[k]]>maxN) maxN = sum+arr[i+tripley[k]][j+triplex[k]];
      }
    }
  }
  // printf("4 : maxN : %d\n",maxN);
  //2 가로
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(j+1>=m) break;
      sum = arr[i][j]+ arr[i][j+1];
      // printf("NUM 5 , sum : %d\n",sum);
      for(k=0;k<8;k+=2){
        if(i+doublex[k]<0||i+doublex[k+1]<0||j+doubley[k]<0||j+doubley[k+1]<0||i+doublex[k]>=n||i+doublex[k+1]>=n||j+doubley[k]>=m||j+doubley[k+1]>=m) continue;
          // printf("%d %d %d %d\n",i+doublex[k],i+doublex[k+1],j+doubley[k],j+doubley[k+1]);
          if(sum+arr[i+doublex[k]][j+doubley[k]]+arr[i+doublex[k+1]][j+doubley[k+1]]>maxN) {
            maxN = sum+arr[i+doublex[k]][j+doubley[k]]+arr[i+doublex[k+1]][j+doubley[k+1]];
            // printf("%d\n",maxN);
          }
      }
    }
  }
  // printf("5 : maxN : %d\n",maxN);
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(i+1>=n) break;
      sum = arr[i][j] + arr[i+1][j];
      for(k=0;k<4;k+=2){
        if(i+doublex1[k]<0||i+doublex1[k+1]<0||j+doubley1[k]<0||j+doubley1[k+1]<0||i+doublex1[k]>=n||i+doublex1[k+1]>=n||j+doubley1[k]>=m||j+doubley1[k+1]>=m) continue;
          if(sum+arr[i+doublex1[k]][j+doubley1[k]]+arr[i+doublex1[k+1]][j+doubley1[k+1]]>maxN) maxN = sum+arr[i+doublex1[k]][j+doubley1[k]]+arr[i+doublex1[k+1]][j+doubley1[k+1]];
        }
    }
  }
  // printf("6 : maxN : %d\n",maxN);
}

int main(){
  int i,j;

  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      scanf("%d",&arr[i][j]);
    }
  }
  find();
  printf("%d",maxN);
  return 0;
}
