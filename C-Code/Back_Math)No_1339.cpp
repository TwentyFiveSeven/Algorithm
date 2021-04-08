#include<iostream>
#include<algorithm>
using namespace std;

int alpha[27],arr[9][11],coun[11],n;
char input[11];

void funcMath(){
  int mul=1,i,j,sum=0,value=9;;
  for(i=1;i<=8;i++){
    for(j=0;j<=9;j++){
        if(arr[i][j]!=0){
          alpha[arr[i][j]] += mul;  //해당 알파벳의 값을 구한다.
        }
    }
    mul *=10;
  }

  sort(alpha+1,alpha+27+1,greater<int>());  //크기 순으로 정렬
  for(i=1;i<=26;i++){
    if(alpha[i] ==0)  //0의 값이 나올 때 까지 9~1까지의 값을 곱해준다.
      break;
    sum += alpha[i]*(value--);
  }
  printf("%d",sum);

}

int main(){
  char temp;
  int i=1,j,count=1,index=1,Rcount=1,k;
  scanf("%d",&n);
  scanf("%c",&temp);

  while(1){ //배열을 만들어 자릿수별로 영어를 저장한다(숫자로 저장)
    if(Rcount == n+1)break; //엔터가 n+1번 들어오면 종료.
    scanf("%c",&temp);  //문자를 char형으로 받는다.
    if(temp =='\n'){  //엔터가 입력되면
      for(j=count-1;j>=1;j--){  //input에 누적된 입력 값을 1~26에 해당하는 수로 바꿔서 arr배열에 입력해준다.
        index = coun[i]++;
        arr[i++][index]=input[j]-64;
      }
      i=1;
      count=1;
      Rcount++;
      continue;
    }else{
      input[count++] = temp;
    }
  }
  funcMath();
  return 0;
}
