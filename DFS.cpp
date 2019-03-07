#include <iostream>
#include <stack>

using namespace std;

int **vv;
int **a;
int *v;
int n;
int count;

void visit(int i,int save){
  int j;
  if(count !=0){
    v[i] =1;
  }
  for(j=1;j<=n;j++){
    if(a[i][j]==1&&v[j]==0){
      vv[save][j]=1;
      count++;
      visit(j,save);
    }
  }
}

int main(){
  int i,k;

  cin>>n;
  a=new int*[n+1];
  vv=new int*[n+1];
  v = new int[n+1];

  for(i=1;i<=n;i++){
    a[i]=new int[n+1];
    vv[i]=new int[n+1];
    for(k=1;k<=n;k++){
      cin>>a[i][k];
      vv[i][k]=0;
    }
  }

  for(int m=0;m<=n;m++){
    v[m]=0;
  }

  for(k=1;k<=n;k++){
    for(i=1;i<=n;i++)
      v[i]=0;
    count=0;
    visit(k,k);
  }

   for(k=1;k<=n;k++){
    for(i=1;i<=n;i++){
      cout<<vv[k][i]<<" ";
    }
    if(k!=n)
      cout<<"\n";
  }

  return 0;
}
