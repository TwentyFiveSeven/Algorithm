#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,arr[20][20],maxN;
int xi[4] = {0,0,-1,1};
int yi[4] = {-1,1,0,0};

int check(int arr[][20],int temp[][20]){  //같은 것이면 다시 재귀하지않는다.
  int i,j,flag=0;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(arr[i][j] !=temp[i][j]) flag=1;
    }
  }
  if(flag) return 1;
  return 0;
}

int BF(int count){
  if(count ==5) return 0;
  int i,j,k,m,temp[20][20]={0,};  //임시 temp배열 생성
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      temp[i][j] = arr[i][j];

  for(k=0;k<4;k++){
    for(i=0;i<n;i++){
      vector<int> temp;
      for(j=0;j<n;j++){
        if((k<2 ? arr[j][i] : arr[i][j])!=0){ //0이 아닌 수들은 제외. 0,1번째는 위 아래 이므로 행, 열을 뒤집어준다.
          temp.push_back(k<2 ? arr[j][i] : arr[i][j]);  // 0,1 일 때는 행, 열을 뒤집어준다.
        }
      }
      if(k==1 || k==3){ //1 ,3 일 떄는 행의 앞 뒤를 뒤집어준다.
        reverse(temp.begin(),temp.end());
      }
      vector<int> at; //같다면 *2연산을 해준다.
      for(m=0;m<temp.size();m++){
        if(m+1<temp.size()&&temp[m]==temp[m+1]){  //m 과 m+1이 같다면 더한다 <- 방향으로 미는 것과 같은 연산.
          at.push_back(temp[m]*2);
          if(temp[m]*2>maxN) {
            maxN = temp[m]*2;
          }
          m++;  //앞에 것 까지 이미 사용했기 때문에 ++;
        }else{  //조건에 맞지않다면 그대로 입력.
          at.push_back(temp[m]);
        }
      }
      for(j=at.size();j<n;j++){ //나머지 뒤에 공간을 n만큼의 크기가 될 떄 까지 0을 추가해준다( 0이 아닌 것만 뻇기 때문)
        at.push_back(0);
      }
      if(k==1 ||k==3)
        reverse(at.begin(),at.end()); //원래로 되돌리기 위한 reverse

      for(j=0;j<n;j++){
        (k<2 ? arr[j][i] : arr[i][j]) = at[j];  //연산값을 원래 배열에 넣어준다.
      }
    }
    if(check(arr,temp)){  //값이 변했다면
      BF(count+1);  //재귀호출.
    }
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        arr[i][j] = temp[i][j]; // 바뀐 값을 다시 원래 값으로 되돌린다.
      }
    }
  }
}

int main(){
  int i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%d", &arr[i][j]);
      if(arr[i][j]>maxN) maxN = arr[i][j];
    }
  }
  BF(0);
  printf("%d",maxN);
  return 0;
}
