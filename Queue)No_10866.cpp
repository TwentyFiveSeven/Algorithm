#include<iostream>
#include<vector>
using namespace std;
vector<int> V;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  string s,tmp,tmp2;
  cin>>n;
  n+=1;
  while(n--){
    getline(cin,s);
    tmp = s.substr(0,2);
    if(tmp == "pu"){
      int i = s.find("_");
      tmp = s.substr(i+1,4);
      int j = s.find(" ");
      tmp2 = s.substr(j+1,s.size()-(j+1));
      if(tmp == "fron"){
        V.insert(V.begin(),atoi(tmp2.c_str()));
      }else if(tmp == "back"){
        V.push_back(atoi(tmp2.c_str()));
      }
    }else if(tmp == "po"){
      if(V.empty()){
        cout<<"-1\n";
        continue;
      }
      int i = s.find("_");
      tmp = s.substr(i+1,4);
      if(tmp == "fron"){
        cout<<V.front()<<"\n";
        V.erase(V.begin());
      }else if(tmp == "back"){
        cout<<V.back()<<"\n";
        V.pop_back();
      }
    }else if(tmp == "si"){
      cout<<V.size()<<"\n";
    }else if(tmp == "em"){
      cout<<V.empty()<<"\n";
    }else if(tmp == "fr"){
      if(V.empty()){
        cout<<"-1\n";
        continue;
      }
      cout<<V.front()<<"\n";
    }else if(tmp == "ba"){
      if(V.empty()){
        cout<<"-1\n";
        continue;
      }
      cout<<V.back()<<"\n";
    }
  }
  return 0;
}
