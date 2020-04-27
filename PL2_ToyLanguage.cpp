#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;
vector<string> Tree;
stack<int> Stack;

int selectMenu();
int Fileload();
int interactiveMode();
string Result(string s);
int checkBlank(string s);
string Exception(int N);
int makeTree(int i,int index,string s);
void postorder(int index);
int MINUS();
int IF();

int main(){
  int select = 0;
  while(1){
    select = selectMenu();
    switch(select){
      case 1 :
        Fileload();
        break;
      case 2 :
        interactiveMode();
        break;
      case 3 :
        cout<<"프로그램을 종료합니다.";
        return 0;
        break;
    }
  }
}

int selectMenu(){
  int ret = 0;
  cout<<"==================================="<<'\n';
  cout<<"1. File Load"<<'\n';
  cout<<"2. Interactive Mode"<<'\n';
  cout<<"3. Exit"<<'\n';
  cout<<"==================================="<<'\n';
  cout<<"메뉴를 선택하세요 >> ";
  cin>>ret;
  cout<<'\n';
  return ret;
}

int Fileload(){
  int size =0,flag =1;
  vector<string> S;
  string fp = "";
  while(flag){
    cout<<"파일명을 입력하세요 >> ";
    cin>>fp;
    ifstream openFile(fp.data());
    if(openFile.is_open()){
      cout<<"\n파일 내용은"<<'\n';
      cout<<"-----------------------------------"<<'\n';
      string line;
      while(getline(openFile,line)){
        S.push_back(line);
        cout<<line<<'\n';
      }
      openFile.close();
      flag = 0;
    }else{
      cout<<"\n파일 이름이 존재하지 않습니다."<<'\n';
      cout<<"-----------------------------------"<<'\n';
    }
  }
  cout<<"-----------------------------------"<<'\n';
  size = S.size();
  for(int i=0;i<size;i++)
  cout<<"결과 : "<<Result(S[i])<<'\n';
  return 0;
}

int interactiveMode(){
  string S="(",C;
  char temp;
  cout<<"문장을 입력하세요."<<'\n';
  cout<<"-----------------------------------"<<'\n';
  cin>>temp;
  getline(cin,C);
  S +=C;
  cout<<"\n-----------------------------------"<<'\n';
  cout<<"결과 : "<<Result(S)<<'\n';
  cout<<"-----------------------------------"<<'\n';
  return 0;
}

string Result(string s){
  int size = checkBlank(s);
  if(size <= 0){  //예외처리
    return Exception(size);
  }
  int Vsize = 1<<(size+2);
  Tree.clear();
  Tree.resize(Vsize);
  makeTree(0,0,s);
  while(!Stack.empty()) Stack.pop();
  postorder(0);
  return to_string(Stack.top());
}

int checkBlank(string s){
  vector<char> V;
  int ret = 0;
  int size = s.size();
  for(int i=0;i<size;i++){
    if(s[i] == ' ') continue;
    if(s[i] != '('&&s[i] != ')' && s[i] !='-')
    if(s[i]<'0' || s[i]>'9')
    if(s[i]<'A' || s[i] > 'Z')
    return -1; //알파벳과 '-'를 제외한 기호입력시 에러
    if(s[i] ==')'){
      V.pop_back();
      ret++;
    }
    else if(s[i] == '(')
    V.push_back('(');
    else if(s[i] >= 'A' && s[i] <='Z'){
      int index = s.find(' ',i);
      string temp = s.substr(i,index-i);
      if(temp != "MINUS" && temp != "IF")
      return -2; // undefined
      i = index;
    }else if(s[i] == '-' || (s[i]>='0'&&s[i]<='9')){
      if(s[i] == '-')
      if(s[i+1] =='-')
      return -3; // -- 연속입력 에러
      while(s[i] != ' ' && s[i] != ')'){
        if(s[i] == '.')
        return -4;  // 정수가 아닌 실수 인지 확인
        i++;
      }
      i -=1; //s[i] 가 )가 되는 것을 방지
    }
  }
  if(V.size() > 0)
  return -5;  //숫자가 안맞거나 방향이 잘못됐을 때
  return ret;
}

string Exception(int N){
  if(N==-1){
    return "오직 알파벳, \"-\", \"(\", \")\" 만 입력할 수있습니다.";
  }else if(N==-2){
    return "undefined.";
  }else if(N==-3){
    return "\"-\"는 연속해서 입력할 수 없습니다.";
  }else if(N==-4){
    return "숫자가 들어갈 자리에 정수가 아닌 실수가 입력되었습니다.";
  }else if(N==0 || N==-5){
    return "\")\"의 위치 또는 방향이 적절하지 않습니다.";
  }else{
    return "Unkown Error";
  }
}

int makeTree(int i,int index,string s){
  int size = s.size();
  if(i > size) return i;
  for(int j=i;j<size;j++){
    if(s[j] == '(' || s[j] == ' ') continue;
    if(s[j] == 'M'){
      Tree[index] = "-";
      j+=5;
      j = makeTree(j+1,index*2+1,s);
      index++;
    }else if(s[j] == 'I'){
      Tree[index] = "i";
      j+=2;
      j = makeTree(j+1,index*2+1,s);
      index++;
    }else if(s[j] == '-' || (s[j]>='0' && s[j]<='9')){
      int save = j;
      while(s[j] != ' ' && s[j] != ')') j++;
      j--;
      Tree[index] = s.substr(save,j-save+1);
      index++;
    }else if(s[j] == ')'){
      return j;
    }
  }
  return i;
}

void postorder(int index){
  if(Tree[index] == "\0") return;
  postorder(index*2+1);
  postorder(index*2+2);
  if(Tree[index] == "-"){
    Stack.push(MINUS());
  }else if(Tree[index] == "i"){
    Stack.push(IF());
  }else{
    Stack.push(atoi(Tree[index].c_str()));
  }
}

int MINUS(){
  int b = Stack.top();
  Stack.pop();
  int a = Stack.top();
  Stack.pop();
  a = a-b;
  return a;
}

int IF(){
  int b = Stack.top();
  Stack.pop();
  int a = Stack.top();
  Stack.pop();
  if(a <= 0) b = 0;
  return b;
}
