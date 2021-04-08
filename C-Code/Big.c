#include<stdio.h>
#include<stdlib.h>
#include "openssl/bn.h"
#define BIT_SIZE 16

int SSU_SEC_BN_Poly_Init(BIGNUM *poly[],int n){
  for(int i=0; i<=n;i++){
    BN_rand(poly[i],BIT_SIZE,1,0);
  }
  return 0;
}

BIGNUM *SSU_SEC_BN_Poly_Compute(BIGNUM *poly[], int n, BIGNUM *x){
  BN_CTX *ctx = NULL;
  ctx = BN_CTX_new();
  BIGNUM *ret = poly[0];
  for(int i=1;i<=n;i++){
    for(int j=0;j<i;j++){
      BN_mul(poly[i],poly[i],x,ctx);
    }
    BN_add(ret,ret,poly[i]);
  }
  return ret;
}

int main(){
  int n;
  BN_CTX *ctx = NULL;
  ctx = BN_CTX_new();
  BIGNUM **poly,*ans,*x;
  scanf("%d",&n);
  poly = (BIGNUM **)malloc(sizeof(BIGNUM *)*(n+1));
  for(int i=0; i<=n;i++){
    poly[i]= BN_CTX_get(ctx);
  }
  SSU_SEC_BN_Poly_Init(poly,n);
  x = BN_CTX_get(ctx);
  BN_rand(x,BIT_SIZE,1,0);
  ans = SSU_SEC_BN_Poly_Compute(poly,n,x);
  printf("n : %d\n",n);
  printf("x : ");
  BN_print_fp(stdout,x);
  printf("\n");
  printf("f(x) : ")
  BN_print_fp(stdout,ans);
  printf("\n");
  return 0;
}
