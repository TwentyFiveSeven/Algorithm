#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
int l,c;
char arr[16];

void code(int ans[],int length,int point){
  int i,j,z,m;
  char temp;
  if(length == l+1){  //ans의 저장 길이가 l만큼이 될 때 까지 ans에 값을 대입한다.
    z=0;m=0;
    string S;
    for(i=1;i<=l;i++){
      temp = arr[ans[i]];
      S += temp;
      if(temp =='a'||temp=='e'||temp =='o'||temp == 'u'||temp=='i'){    //모음이라면 모음 count++
        m++;
      }else{z++;} //자음이라면 자음 count++
    }
    if(m>=1&&z>=2){
      cout<<S<<endl;
    }
    return;
  }
  for(i=point;i<=c;i++){  //point부터 시작 하는 값을 가지며, length가 1~l 이 될 떄 까지 ans의 값을 계속해서 추가한다.
    ans[length] = i;
    code(ans,length+1,i+1); //다음 length의 값을 추가하기위함. 만약 length가 l과 같다면 출력부분으로 넘어간다.
  }

}

int main(){
  int i,j,gb=0;
  int ans[16]={0};
  scanf("%d %d",&l,&c);
  scanf("%c",&gb);

  for(i=1;i<=c;i++){
    scanf("%c",&arr[i]);
    scanf("%c",&gb);
  }
  sort(arr+1,arr+c+1);  //주의 사항 !!!!!!!!! +1부터 정렬했으면 끝도 +1만큼 더 정렬해줘야한다.
  code(ans,1,1);

  return 0;
}
