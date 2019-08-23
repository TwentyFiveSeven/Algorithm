#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> fail(string p){ //실패함수 = > 시간을 줄여주는 함수.
  int i=1,j=0,sizeN = p.size();
  vector<int> pi(sizeN,0); //검사하는 글자만큼 size할당
  for(i=1;i<sizeN;i++){
    while(j>0&&p[i] != p[j]) //p[i]랑 p[j]가 같을 때 까지 or j==0일 떄 까지 진행
      j = pi[j-1]; //현재에서 틀렸으므로 현재 이전에서 같은 부분으로 이동
    if(p[i] == p[j])
      pi[i] = ++j;  //같으면 j+1 저장
  }
  return pi;
}

vector<int> kmp(string t,string p){
  int i=0;
  vector<int> ans;
  vector<int> pi = fail(p);
  int sizeT = t.size(),sizeP = p.size(),j=0;
  for(i=0;i<sizeT;i++){
    while(j>0&&t[i] != p[j])  //t와 p가 같을 때 까지 j=pi[j-1];
      j = pi[j-1];
    if(t[i] == p[j]){ //만약 같다면.
      if(j == sizeP-1){ //같을 때 j가 마지막이라면 = t안에 p가 있다면
        ans.push_back(i-sizeP+2); //ans에 시작이 몇번째인지 저장
        j = pi[j]; //i++ 자리에 pi[j]부터 다시 비교
      }else{
        j++;
      }
    }
  }
  return ans;
}

int main(){
  int i;
  string t,p;
  getline(cin,t); //공백도 입력 받기 때문에 getline사용
  getline(cin,p);
  vector<int> ans = kmp(t,p); //정답을 return
  printf("%d\n",ans.size());
  for(i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}
