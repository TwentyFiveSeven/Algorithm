#include<iostream>
using namespace std;

int N,L,arr[100][100],ans;

void bf1(){ //가로 탐색.
  int save=0,i,j,count=0;
  for(i=0;i<N;i++){
    count =1;
    save = arr[i][0]; //시작 수를 바로 save에 저장.
    for(j=1;j<N;j++){
      if(arr[i][j] == save){  //만약 현재 수와 이전 수가 같다면 count++
        count++;
      }else if(arr[i][j]<save){ //현재 수가 이전 수 보다 작다면
        if(save-arr[i][j]>1) break; //차이가 2이상이라면 해당 행은 지날 수 없는 길이다(break)
        save = arr[i][j]; //save에 현재 수 저장.
        count = 0;  //count =0;
        while(arr[i][j] ==save){  //현재 수가 앞으로 몇개나 이어지는지 확인.
          j++;
          count++;
        }
        j-= 1;
        if(count<L) break;  //만약 L보다 길거나 같게 이어지면 통과 아니면 break
        count -=L;  //후에 앞에 카운트 L개를 사용했기 때문에 count-L
      }else if(arr[i][j]>save){ //만약 현재 수가 이전 수 보다 크다면
        if(arr[i][j]-save>1) break; //차이가 2 이상이라면 해당 행은 지날 수 없는 길(break);
        save = arr[i][j]; //save에 현재 수 저장.
        if(count<L) break;  // 만약 여태까지의 길이가 L보다 작으면 break;
        count =1; //현재 수를 포함해야 하므로 count = 1;
      }
      if(j ==N-1) ans++;
    }
  }
}

void bf2(){ //세로 탐색
  int save=0,i,j,count=0;
  for(i=0;i<N;i++){
    count =1;
    save = arr[0][i];
    flag = 1;
    for(j=1;j<N;j++){
      if(arr[j][i] == save){
        count++;
      }else if(arr[j][i]<save){
        if(save-arr[j][i]>1) break;
        save = arr[j][i];
        count = 0;
        while(arr[j][i] ==save){
          j++;
          count++;
        }
        j-= 1;
        if(count<L) break;
        count -=L;
      }else if(arr[j][i]>save){
        if(arr[j][i]-save>1) break;
        save = arr[j][i];
        if(count<L) break;
        count =1;
      }
      if(j ==N-1) ans++;
    }
  }
}

int main(){
  int i,j;
  scanf("%d %d",&N,&L);
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      scanf("%d",&arr[i][j]);
    }
  }
  bf1();
  bf2();
  printf("%d",ans);
  return 0;
}
