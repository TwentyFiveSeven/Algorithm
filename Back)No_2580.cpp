#include<iostream>
using namespace std;

bool row[10][10], col[10][10], square[10][10];  //☆☆☆시간을 줄이기 위해 메모리를 이용한다 ☆☆☆
int arr[10][10];    //row는 행에 따른 1~9의 값이 존재 하는지, col는 열에 따른 1~9의 값이 존재하는지
int Q[81];        //square은 3X3배열에 따른 1~9의 값이 존재하는지를 나타내고, Q는 0이 있는 위치를 합으로 나타낸다.
int n;

int number(int x,int y){
  return (((x-1)/3)*3)+(y-1)/3 +1;    // 3X3배열을 9개로 나눠 구분한다.
}
int printSdoku(){
  int i,j;
  for(i=1;i<=9;i++){
    for(j=1;j<=9;j++){
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
}

void sdoku(int depth){
  int i,j,x,y;
  if(depth==n){ //만약 depth가 n 즉 0이 있는 갯수만큼을 모두 채웠다면 값을 출력.
    printSdoku();
    exit(0);
  }
  x = (Q[depth]/9)+1; //Q에 저장된 합을 다시 나누어 x,y로 구분한다.
  y = Q[depth]%9+1;
  for(i=1;i<=9;i++){
    if(row[x][i]||col[y][i]||square[number(x,y)][i]) continue;  //만일 현재 점에서의 행,열,3x3배열에 i가 존재하면 continue -> i++
    arr[x][y] = i;
    row[x][i] = col[y][i] = square[number(x,y)][i] = true;  // 현재 점의 행,열,3X3배열에 i가 있음을 표시한다.
    sdoku(depth+1); //depth+1을 통해서 다음 0의 위치를 채운다.
    arr[x][y] = 0;  //실패하게 되면 다시 0으로 초기화
    row[x][i] = col[y][i] = square[number(x,y)][i] = false;
  }
}

int main(){
  int i,j,tmp;
  for(i=1;i<=9;i++){
    for(j=1;j<=9;j++){
      scanf("%d",&tmp);
      arr[i][j] = tmp;
      if(!tmp){
          Q[n++] = (i-1)*9+j-1;   //0이 존재 하는 위치를 합으로 나타낸다 .
      }
      else{
        row[i][tmp] = true; //0이 아닌곳은 true
        col[j][tmp] = true;
        square[number(i,j)][tmp] = true;
      }
    }
  }
  sdoku(0);
  return 0;
}
