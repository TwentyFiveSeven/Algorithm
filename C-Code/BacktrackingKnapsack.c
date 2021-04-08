#include<stdio.h>
#include<stdlib.h>

int promising(int i, int profit, int weight){
  int j,k;
  int totweight;
  float bound;

  if(weight >= W){
    return 0;
  }
  else{
    j = i+1;
    bound = profit;
    totweight = weight;
    while((j <=n)&&(totweight+w[j]<=W)){
      totweight = totweight + w[j];
      bound = bound + p[j];
      j++;
    }
    k=j;
    if(k<=n){
      bound = bound + (W-totweight)*(p[k]/w[k]);
    }
    return bound>maxprofit;
  }
}

void knapsack(int i,int profit, int weight){
  if(weight <= W && profit > maxprofit){
    maxprofit = profit;
    numbest = i;
    bestset = include;
  }

  if(promising(i,profit,weight)){
    include[i+1] = "YES";
    knapsack(i+1, profit+p[i+1],weight + W[i+1]);
    include[i+1] = "NO";
    kanpsack(i+1,profit,weight);
  }
}
