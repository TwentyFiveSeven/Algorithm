#include<iostream>
#include<vector>

using namespace std;
vector<pair<char,char>> V[26];
int n;

void preorder(char root){ //root 왼쪽 오른쪽.
  char left = V[root-'A'].front().first;
  char right = V[root-'A'].front().second;

  printf("%c",root);
  if(left != '.') preorder(left);
  if(right != '.') preorder(right);
}

void inorder(char root){  //왼쪽 root 오른쪽
  char left = V[root-'A'].front().first;
  char right = V[root-'A'].front().second;

  if(left != '.') inorder(left);
  printf("%c",root);
  if(right != '.') inorder(right);
}

void postorder(char root){  //왼쪽 오른쪽 root
  char left = V[root-'A'].front().first;
  char right = V[root-'A'].front().second;

  if(left != '.') postorder(left);
  if(right != '.') postorder(right);
  printf("%c",root);
}

int main(){
  int i,j;
  char root=0,left=0,right=0;
  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf(" %c %c %c",&root,&left,&right);
    V[root-'A'].push_back(make_pair(left,right));//V[root-'A']는 부모를 뜻하고 그 안의 값 left,right는 자식이다.
  }

  preorder('A');
  printf("\n");
  inorder('A');
  printf("\n");
  postorder('A');
  printf("\n");

  return 0;
}
