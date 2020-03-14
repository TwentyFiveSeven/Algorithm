#include<iostream>
#include<string.h>
using namespace std;
int test[50][50],input[50][50];
int main(){
  int flag = 0,flag1 =0,T,N,M;
  scanf("%d",&T);
  while(T--){
		scanf("%d %d",&N,&M);
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				scanf("%d",&input[i][j]);
			}
		}
    for(int i=0;i<N-1;i++){
      for(int j=0;j<M-1;j++){
        for(int k=i;k<i+2;k++){
          for(int m = j;m<j+2;m++){
            if(input[k][m] == 0){
              flag = 1;
              break;
            }
          }
          if(flag == 1 )
            break;
        }
        if(flag == 1){
          flag = 0;
          continue;
        }else{
          for(int k=i;k<i+2;k++){
            for(int m = j;m<j+2;m++){
              test[k][m] = 1;
            }
          }
        }
      }
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(input[i][j] != test[i][j]){
          flag1 = 1;
          break;
        }
      }
      if(flag1 == 1){
        break;
      }
    }
    if(flag1 ==1)
      printf("NO\n");
    else
      printf("YES\n");
    flag1 = 0;
		memset(input,0,sizeof(input));
    memset(test,0,sizeof(test));
  }
	return 0;
}
