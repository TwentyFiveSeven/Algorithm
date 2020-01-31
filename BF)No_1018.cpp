#include<iostream>
#include<algorithm>
using namespace std;
char arr[50][50];
char temp[8][8];
char ch[2] = {'B','W'};

int main(){
  int n,m,min = 100001;
  char c,tmp;
  scanf("%d %d",&n,&m);
  scanf("%c",&tmp);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%c",&arr[i][j]);
    }
    scanf("%c",&tmp);
  }
  for(int i=0;i<n-8+1;i++){
    for(int j=0;j<m-8+1;j++){
      for(int q=0;q<2;q++){
        for(int w = 0;w<8;w++){
          for(int e = 0;e<8;e++){
            temp[w][e] = arr[w+i][e+j];
          }
        }
        int checkV = 0;
        int check = q;
        for(int k=0;k<8;k++){
          for(int m=0;m<8;m++){
            if(temp[k][m] != ch[check]){
              temp[k][m] = ch[check];
              checkV++;
            }
            check = (check+1)%2;
          }
          check = (check+1)%2;
        }
        if(checkV<min)
          min = checkV;
      }
    }
  }
  printf("%d",min);
  return 0;
}
