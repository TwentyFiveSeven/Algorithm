#include<iostream>
#include<algorithm>
using namespace std;
int arr[5][5],ans[5][5],first[5][5];

void check(int n, long long b){
  if(b/2 == 0) return;
  check(n,b/2);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ans[i][j] = 0;
      for(int p=0;p<n;p++){
        ans[i][j] = (ans[i][j] + arr[i][p]*arr[p][j])%1000;
      }
    }
  }
  if(b%2){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        arr[i][j]= 0;
        for(int p=0;p<n;p++){
          arr[i][j] = (arr[i][j] + ans[i][p]*first[p][j])%1000;
        }
      }
    }
  }else{
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        arr[i][j] = ans[i][j];
      }
    }
  }
    return;
}

int main(){
  int n;
  long long b;

  scanf("%d %lld",&n,&b);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&arr[i][j]);
      arr[i][j] %= 1000;
      first[i][j] = arr[i][j];
    }
  }
  check(n,b);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}
