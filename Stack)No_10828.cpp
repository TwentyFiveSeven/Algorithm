#include<iostream>
#include<string.h>
using namespace std;

typedef struct node{
  int val;
  node* next;
}node;

typedef struct stack{
  node* top;
  int length;
}Stack;
Stack stack;

int size(){
  return stack.length;
}
int empty(){
  if(size()>0) return 0;
  else return 1;
}
void top(){
  if(size() == 0){
    printf("-1\n");
    return;
  }
  printf("%d\n",stack.top->val);
  return;
}
node* Neww(int i){
  node* N;
  N = (node *)malloc(sizeof(node));
  N->val = i;
  N->next = NULL;
  return N;
}

void push(int i){
  node* N = Neww(i);
  if(empty()){
    stack.top = N;
    stack.length = 1;
  }else{
    node* temp = stack.top;
    stack.top = N;
    stack.top->next = temp;
    stack.length++;
  }
}

void pop(){
  if(empty()){
    printf("-1\n");
    return;
  }
  node* temp = stack.top;
  stack.top = stack.top->next;
  int ret = temp->val;
  temp->next = NULL;
  stack.length--;
  printf("%d\n",ret);
  return;
}


int main(){
  char t;
  string s,tmp;
  int n,value;
  scanf("%d",&n);
  scanf("%c",&t);
  // stack = (Stack *)malloc(sizeof(Stack));
  for(int i=0;i<n;i++){
    getline(cin,s);
    tmp = s.substr(0,2);
    if(tmp == "pu"){
      int loc = s.find(' ');
      tmp = s.substr(loc+1,s.size()-5);
      value = atoi(tmp.c_str());
      push(value);
    }else if(tmp == "po"){
      pop();
    }else if(tmp == "si"){
      printf("%d\n",size());
    }else if(tmp == "em"){
      int val = empty();
      printf("%d\n",val);
    }else{//top
      top();
    }
  }
}
