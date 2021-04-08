#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> V;
int head,tail,flag = 0;

int flip(string p){
  int start = 0,size = p.size();
  for(int i=0;i<size;i++){
    if(p[i] == 'D'){
      if(head == tail) return -1;
      if(flag) tail--;
      else head++;
    }else if(p[i] == 'R'){
      flag=(flag+1)%2;
    }
  }
  return 0;
}

void complete(string num){
  int start = 0,size = num.size();
  while(1){
    int tmp = num.find(",",start);
    if(tmp == -1) break;
    int length = tmp - start;
    V.push_back(atoi(num.substr(start,length).c_str()));
    start = tmp+1;
    if(tmp+1 >size-1) break;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t,n;
  string p,num;
  cin>>t;
  while(t--){
    cin>>p;
    cin>>n;
    cin>>num;
    num = num.substr(1,num.size()-2) +',';
    if(num != ",")
      complete(num);
    head = 0; tail = V.size();
    flag = 0;
    int value = flip(p);
    if(value == -1){
      cout<<"error\n";
    }else{
      cout<<"[";
      if(!flag){
        for(int i=head;i<tail;i++){
          cout<<V[i];
          if(i != tail-1){
            cout<<",";
          }
        }
        cout<<"]\n";
      }else{
        for(int i=tail-1;i>=head;i--){
          cout<<V[i];
          if(i != head){
            cout<<",";
          }
        }
        cout<<"]\n";
      }
    }
    V.clear();
  }
  return 0;
}
