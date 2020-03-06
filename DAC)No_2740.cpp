#include<iostream>
using namespace std;
int arr1[102][102],arr2[102][102];
int n1,m1,n2,m2;

void mul(){
  int val;
  for(int i=0;i<n1;i++){
    for(int j=0;j<m2;j++){
      val = 0;
      for(int k=0;k<m1;k++){
        val += arr1[i][k]*arr2[k][j];
      }
      printf("%d ",val);
    }
    printf("\n");
  }
}

int main(){
  scanf("%d %d",&n1,&m1);
  for(int i=0;i<n1;i++){
    for(int j=0;j<m1;j++){
      scanf("%d",&arr1[i][j]);
    }
  }
  scanf("%d %d",&n2,&m2);
  for(int i=0;i<n2;i++){
    for(int j=0;j<m2;j++){
      scanf("%d",&arr2[i][j]);
    }
  }
  mul();
  return 0;
}
