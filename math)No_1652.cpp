#include<iostream>
using namespace std;

int arr[101][101];

int main(){
  int n,i,j,check=0,count=0;
  char tmp;
  scanf("%d",&n);
  scanf("%c",&tmp);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      scanf("%c",&tmp);
      if(tmp=='X') arr[i][j] = 1;
    }
    scanf("%c",&tmp);
  }
  for(i=1;i<=n;i++){  //가로
    check =0;
    for(j=1;j<=n;j++){
      if(arr[i][j] == 0) check++;
      else check=0;
      if(check==2) count++;   //만일 한줄에 2개짜리가 여래개있다면 모두 세어야한다.(point)
    }
  }
  printf("%d ",count);
  count =0;
  for(i=1;i<=n;i++){  //세로
    check =0;
    for(j=1;j<=n;j++){
      if(arr[j][i] == 0) check++;
      else check=0;
      if(check==2) count++; //만일 한줄에 2개짜리가 여래개있다면 모두 세어야한다.(point)
    }
  }
  printf("%d",count);
  return 0;
}
