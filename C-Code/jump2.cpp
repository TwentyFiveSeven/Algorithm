#include <iostream>
#include <cstdio>
using namespace std;


int main(){
    int n,i,j,x;
    int **a;
    scanf("%d",&n);

    a = new int*[n];
    for(i=0; i<n;i++){a[i] = new int[n];}
    a[0][0]=1;

    for(i=0; i<n;i++){
      for(j =0;j<n;j++){
        scanf("%d",&x);
        if(!a[i][j]){
          continue;
        }
        if(i+x<n) a[i+x][j] = 1;
        if(j+x<n) a[i][j+x] = 1;
      }
    }
    puts(a[n-1][n-1] ? "HaruHaru" : "Hing");
    return 0;
}
