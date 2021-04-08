#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int* S;
int n;

void partition(int low, int high, int* pivotpoint){
  int i,j,save;
  int pivotitem;
  pivotitem = S[low-1]; // pivotitem을 위한 첫번쨰 항목을 고른다
  j=low;
  for(i=low+1;i<=high;i++){ //exchange S[i] and S[j];
    if(S[i-1]<pivotitem){
      j++;
      save = S[i-1];
      S[i-1]=S[j-1];
      S[j-1]=save;
    }
  }
    *pivotpoint =j;
    printf("pivotpoint : %d\n",*pivotpoint);
    printf("바꾸기전 S : ");
    for(int i=0; i<n;i++){
      printf("%d ",S[i]);
      if(i==n-1)
        printf("\n\n");
    }

    save=S[low-1];//exchange S[low] and S[pivotpoint]; // pivotitem 값을  pivotpoint에 넣는다.
    S[low-1]=S[*pivotpoint-1];
    S[*pivotpoint-1]=save;


    printf("바꾼 후 S : ");
    for(int i=0; i<n;i++){
      printf("%d ",S[i]);
      if(i==n-1)
        printf("\n\n");
    }
}

void quicksort(int low, int high){
  printf("low : %d, high : %d\n",low,high);
  int pivotpoint=0;
  if(high>low){
    partition(low,high,&pivotpoint);
    printf("partitoin 후에 pivot %d \n",pivotpoint);
    quicksort(low,pivotpoint-1);
    quicksort(pivotpoint+1,high);
  }
}

int main(){
  int i=0;
  scanf("%d",&n);

  S = (int*)malloc(sizeof(int)*n);

  for(i;i<n;i++){
    scanf("%d",&S[i]);
  }
  quicksort(1,n);
  printf("\n");
  for(int i=0;i<n;i++)
  printf("%d ",S[i]);
}
