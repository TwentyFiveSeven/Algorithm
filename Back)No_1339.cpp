#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
int coun[9];
int n,arr[11][11],num[11],alpha[27],ans;
char input[9];
int promising(int depth,int index,int value){
  int tmp = alpha[arr[depth][index]];
  if(tmp)
    return alpha[arr[depth][index]];
  else{
    return 0;
  }
}

void back(int depth,int index,int value){
  int i,j,plus=0,k,mul=1;
  for(i=9;i>=1;){
    mul =1;
    if(depth<1)
      break;
    if(!arr[depth][index]){
      depth -=1;
      index=0;
      continue;
    }
    plus = promising(depth,index,i);
    if(!plus){
      num[i] =1;
      alpha[arr[depth][index]] =i;
      // printf("case : 0, depth : %d, value : %d\n",depth,i);
      for(k=1;k<depth;k++) mul*=10;
      ans += mul*i;
      // printf("ans : %d\n",ans);
      i--;index++;
    }else{
      for(k=1;k<depth;k++) mul*=10;
      ans += mul*plus;
      // printf("case : 1, depth : %d, value : %d\n",depth,plus);
      // printf("ans : %d\n",ans);
      index++;
    }
  }
  // if(depth<1||value<1) return;
  // if(!arr[depth][index]){
  //   back(depth-1,1,value);
  //   return;
  // }
  // plus = promising(depth,index,value);
  // if(!plus){
  //   num[value] =1;
  //   alpha[arr[depth][index]] =value;
  //   ans += ((int)(pow((doble)10,(double)depth)))*value;
  // }
}

int main(){
  char temp;
  int i=1,j,count=1,index=1,Rcount=1,k;
  scanf("%d",&n);
  scanf("%c",&temp);
  // for(k=0;k<=9;k++){
  //   coun[k] =1;
  // }

  while(1){
    if(Rcount == n+1)break;
    scanf("%c",&temp);
    if(temp =='\n'){
      for(j=count-1;j>=1;j--){
        index = coun[i]++;
        arr[i++][index]=input[j]-64;
        // printf("i : %d, index : %d,count : %d\n",i,index,count);
      }
      i=1;
      count=1;
      Rcount++;
      continue;
    }else{
      input[count++] = temp;
      // printf("i : %d, index : %d,count : %d\n",i,index,count);
    }
  }
  // for(i=1;i<=10;i++){
  //   for(j=0;j<=8;j++){
  //     printf("%d ",arr[i][j]);
  //   }
  //   printf("\n");
  // }
  back(10,0,9);
  printf("%d",ans);
}
