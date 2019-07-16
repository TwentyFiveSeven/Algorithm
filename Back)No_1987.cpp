#include<iostream>
#include<algorithm>
using namespace std;
int maxN = 0,r,c;
int xi[4] = {1,-1,0,0};
int yi[4] = {0,0,-1,1};

int promising(char tmp,int alpha[]){
  int val = tmp - 64;   // 알파벳은 char형이지만 -64를통해 1~26의 숫자로 배열에 저장
  if(alpha[val] == 0){
    return 1;
  }else{
    return 0;
  }
}

void move(char arr[][21],int alpha[],int count,int x,int y){
  int alpha1[27] ={0};          //중요한 부분 C++의 배열 이동은 call by reference 이므로
  copy(alpha,alpha+27,alpha1);  //다음 차례로 넘어갈 때마다 check배열은 새로 만들어줘야한다.
  int i,j,nx,ny;
  int val = arr[x][y] -64;
  alpha1[val] = 1;
  count++;
  for(i=0;i<4;i++){
    nx = x + xi[i];
    ny = y + yi[i];
    if(nx>=1&&nx<=r&&ny>=1&&ny<=c){
      if(promising(arr[nx][ny],alpha1)){    //현재 위치에 있는 알파벳이 이미 지난 알파벳인지 확인.
        move(arr,alpha1,count,nx,ny);
      }
    }
  }
  if(count>maxN) maxN = count;
}

int main(){
  int i,j,gb=0,count=0;
  int alpha[27]={0};    //체크를 위한 것
  char arr[21][21] = {0}; //배열을 저장

  scanf("%d %d",&r,&c);
  scanf("%c",&gb);

  for(i=1;i<=r;i++){
    for(j=1;j<=c;j++){
      scanf("%c",&arr[i][j]);
    }
    scanf("%c",&gb);
  }

  move(arr,alpha,count,1,1);
  printf("%d",maxN);
  return 0;
}
