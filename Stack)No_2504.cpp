#include<iostream>
#include<vector>

using namespace std;
string s;
vector<char> V;

int main(){
  int ans = 0,sum=0,flag =0;
  getline(cin,s);
  V.push_back(s[0]);
  for(int i=1;i<s.size();i++){
    int size = V.size();
    char temp = s[i];
    int save =0;
    if(s[i] ==')'&&V.back() =='('){ //() 일 때
      int mul=1;
      if(flag !=0){ //만일 연속 두번째 이상의 괄호가 일치하면 무시한다.
        V.pop_back();
        continue;
      }
      for(int j=0;j<V.size()-1;j++){
        if(V[j] == '(') mul*=2; //앞의 곱을 미리 계산한다.
        if(V[j] == '[') mul*=3;
      }
      sum += 2*mul; //()이므로 2에다가 곱해준다
      V.pop_back();
      flag++;
    }else if(s[i] ==']'&&V.back() == '['){
      int mul=1;
      if(flag !=0){
        V.pop_back();
        continue;
      }
      for(int j=0;j<V.size()-1;j++){
        if(V[j] == '(') mul*=2;
        if(V[j] == '[') mul*=3;
        flag++;
      }
      sum += 3*mul;  //[]이므로 3에다가 곱해준다
      V.pop_back();
    }else{
      V.push_back(s[i]);
      flag =0;  //연속하지않으므로 무시하지않고 연산하기 위해 flag = 0
    }
  }
  if(V.size() !=0)
    printf("0");
  else
    printf("%d",sum);
  return 0;
}
