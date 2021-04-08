#include<stdio.h>
#include<stdlib.h>

int promising(index i){
  int j;
  int swit;
  if(i == n-1&&!W[vindex[n-1]][vindex[0]])
    swit = 0;
  else if(i>0 && !W[vindex[i-1]][vindex[i]])
    swit =0;
  else{
    swit = 1;
    j=1;
    while(j<i&&swit){
      if(vindex[i]==vindex[j])
        swit=0;
      j++;
    }
  }
  return swit;
}

void hamiltonian(index i){
  index j;

  if(promising(i))
    if(i ==n-1){
      cout <<vindex[0]through vindex[n-1];
    }
    else{
      for(j=2;j<=n;j++){
        vindex[i+1]=j;
        hamiltonian(i+1);
      }
    }

}
