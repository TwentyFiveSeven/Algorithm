#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
int coun[9],inputcount;
int n,arr[11][11],num[11],alpha[27],maxV;
char input[9];
int promising(int depth,int index){
  int tmp = alpha[arr[depth][index]];
  if(tmp)
    return alpha[arr[depth][index]];
  else{
    return 0;
  }
}

void back(int depth,int index,int ans){
  int i=0,j,mul=1,val =0;
  if(ans>maxV) maxV = ans;
  if((depth<=1&&index>coun[1])||depth<1) {
    printf(" 0 loop , depth : %d, index : %d, ans : %d, i : %d\n",depth,index,ans,i);
    return;
  }
  if(!arr[depth][index]){
    printf(" 1 loop , depth : %d, index : %d, ans : %d, i : %d\n",depth,index,ans,i);
    back(depth-1,0,ans);
    return;
  }
  for(i=9;i>9-inputcount;i--){
    mul=1;
    if(num[i]){
      if(promising(depth,index)){
        for(j=0;j<depth-1;j++) mul*=10;
        val = promising(depth,index);
        ans += mul*val;
        printf(" 2 loop , depth : %d, index : %d, ans : %d, val : %d\n",depth,index,ans,val);
        back(depth,index+1,ans);
        return;
      }else{
        continue;
      }
    }else{
      if(promising(depth,index)){
        for(j=0;j<depth-1;j++) mul*=10;
        val = promising(depth,index);
        ans += mul*val;
        printf(" 3 loop , depth : %d, index : %d, ans : %d, val : %d\n",depth,index,ans,val);
        back(depth,index+1,ans);
        return;
      }else{
        num[i] = 1;
        alpha[arr[depth][index]] = i;
        for(j=0;j<depth-1;j++) mul*=10;
        ans += mul*i;
        printf(" 4 loop , depth : %d, index : %d, ans : %d, i : %d\n",depth,index,ans,i);
        back(depth,index+1,ans);
        num[i] = 0;
        alpha[arr[depth][index]] = 0;
        ans -= mul*i;
        printf(" 5 loop , depth : %d, index : %d, ans : %d, i : %d\n",depth,index,ans,i);
        continue;
      }
    }
  }
}

int main(){
  char temp;
  int i=1,j,count=1,index=1,Rcount=1,k;
  scanf("%d",&n);
  scanf("%c",&temp);

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
      inputcount++;
      input[count++] = temp;
      // printf("i : %d, index : %d,count : %d\n",i,index,count);
    }
  }
  for(i=1;i<=8;i++){
    for(j=0;j<=10;j++){
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  back(8,0,0);
  printf("%d",maxV);
}
